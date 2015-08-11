﻿#pragma once

#include <QtWidgets/QMainWindow>

class DataSource;

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

private:
	QAction* new_action_;
	QAction* open_action_;
	QScopedPointer<DataSource> data_source_;
};