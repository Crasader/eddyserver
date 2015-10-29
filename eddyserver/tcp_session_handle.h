﻿#pragma once

#include "types.h"
#include "net_message.h"
#include "tcp_session.h"


namespace eddy
{
	class IOServiceThreadManager;

	class TCPSessionHandle : public std::enable_shared_from_this < TCPSessionHandle >
	{
		friend class IOServiceThreadManager;

	public:
		TCPSessionHandle();

		virtual ~TCPSessionHandle();

		void send(NetMessage &message);

		void close();

		void dispose();

		bool is_closed() const;

		ThreadID thread_id() const
		{
			return thread_id_;
		}

		TCPSessionID session_id() const
		{
			return session_id_;
		}

		IOServiceThreadManager* thread_manager()
		{
			return io_thread_manager_;
		}

		std::vector<NetMessage>& messages_to_be_sent()
		{
			return messages_to_be_sent_;
		}

		template <typename CompletionHandler>
		void thread_task(ASIO_MOVE_ARG(CompletionHandler) handler)
		{
			io_thread_manager_->thread()->post(handler);
		}

	public:
		virtual void on_connect() = 0;

		virtual void on_message(NetMessage &message) = 0;

		virtual void on_close() = 0;

	private:
		void init(TCPSessionID sid, ThreadID tid, IOServiceThreadManager* manager);

	protected:
		TCPSessionHandle(const TCPSessionHandle &) = delete;
		TCPSessionHandle& operator= (const TCPSessionHandle &) = delete;

	private:
		TCPSessionID				session_id_;
		ThreadID					thread_id_;
		IOServiceThreadManager*		io_thread_manager_;
		std::vector<NetMessage>		messages_to_be_sent_;
	};
}