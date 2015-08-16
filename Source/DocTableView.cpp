﻿#include "DocTableView.h"

#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStyledItemDelegate>


DocTableView::DocTableView(QWidget *parent)
	: QTableWidget(parent)
{
	setColumnCount(5);
	setFocusPolicy(Qt::NoFocus);
	verticalHeader()->setVisible(false);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);

	QStringList header;
	header << tr("Title") << tr("User Name") << tr("Password") << tr("URL") << tr("Notes");
	setHorizontalHeaderLabels(header);
}

DocTableView::~DocTableView()
{

}