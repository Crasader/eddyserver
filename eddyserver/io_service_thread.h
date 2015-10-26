﻿#pragma once

#include <memory>
#include <asio/io_service.hpp>
#include "tcp_session_queue.h"

class TCPSession;
class IOServiceThreadManager;

class IOServiceThread final
{
	friend class IOServiceThreadManager;

public:
	typedef std::shared_ptr<TCPSession> SessionPointer;

public:
	IOServiceThread(IOServiceThreadManager &manager);
	~IOServiceThread() = default;

public:
	void run_thread();

	void join();

	void stop();

	size_t load() const;

	template <typename CompletionHandler>
	void post(ASIO_MOVE_ARG(CompletionHandler) handler)
	{
		io_service_.post(handler);
	}

public:
	ThreadID id() const
	{
		return thread_ != nullptr ? thread_->get_id() : ThreadID();
	}

	asio::io_service& io_service()
	{
		return io_service_;
	}

	IOServiceThreadManager& manager()
	{
		return manager_;
	}

	TCPSessionQueue& session_queue()
	{
		return session_queue_;
	}

private:
	void run();

private:
	IOServiceThread(const IOServiceThread&) = delete;
	IOServiceThread& operator=(const IOServiceThread&) = delete;

private:
	IOServiceThreadManager&					manager_;
	asio::io_service						io_service_;
	std::shared_ptr<std::thread>			thread_;
	std::unique_ptr<asio::io_service::work>	work_;
	TCPSessionQueue							session_queue_;
};