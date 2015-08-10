﻿#pragma once

#include <QtWidgets/QListWidget>

class DataSource;

class FolderView : public QListWidget
{
	Q_OBJECT

public:
	explicit FolderView(QWidget *parent = 0);
	~FolderView();

public:
	void refreshFolders(DataSource *data_source);
};