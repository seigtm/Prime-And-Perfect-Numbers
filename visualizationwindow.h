#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

class VisualizationWindow : public QWidget {

public:
  VisualizationWindow(int rows, int columns, QWidget *parent = 0);

};

