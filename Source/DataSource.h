﻿#pragma once

#include <QMap>
#include <QVector>
#include <QObject>

struct PWData
{
	QString title;
	QString user_name;
	QString pass_word;
	QString url;
	QString notes;
};

class DataSource : public QObject
{
	Q_OBJECT

public:
	enum MessageCode
	{
		CATEGORY_EXISTS,
		CATEGORY_NOT_EXISTS,
	};

public:
	explicit DataSource();
	~DataSource();

public Q_SLOTS:
	void addCategory(const QString &name);
	void deleteCategory(const QString &name);
	void changeCategoryName(const QString &name, const QString &new_name);

Q_SIGNALS:
	void refresh(DataSource *data_source);
	void message(DataSource::MessageCode code, const QString &details);

private:
	QVector<QString> category_order_;
	QMap<QString, QVector<PWData>> all_records_;
};