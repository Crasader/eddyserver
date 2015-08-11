﻿#pragma once

#include <QtWidgets/QMainWindow>
#include "DataSource.h"

class MainWindow final : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = 0);
	
	~MainWindow();

private:
	void createActions();

	void createFileMenu();

private Q_SLOTS:
	void openFile();

	void saveFile();

	void popupMessage(DataSource::MessageCode code, const QString &details);

private:
	QAction* new_action_;
	QAction* open_action_;
	QAction* save_action_;
	QString current_file_;
	QScopedPointer<DataSource> data_source_;
};