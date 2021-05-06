#pragma once

#include "myMaths.h"

#include <QWidget>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>

#include <QMessageBox>

class VisualizationWindow : public QWidget {

public:

  // Конструктор класса, принимающий n - конечное число диапазона.
  VisualizationWindow(const uint n, QWidget *parent = 0);

  // Метод визуального отображения процесса поиска простых чисел.
  // Алгоритм: Решето Эратосфена.
  void calculatePrimes();

private:

  // Приватные методы класса окна визуализации:
  void initTable(); // Добавление таблицы на форму.
  void fillTable(); // Заполнение таблицы числами от 2 до n.

  // Приватные поля класса окна визуализации:
  uint n;            // Конечное число диапазона.
  uint tableRows;    // Количество рядов таблицы.
  uint tableColumns; // Количество колонок таблицы.

  QTableWidget *table;  // Графический виджет таблицы.
  QHBoxLayout  *layout; // Главный layout формы.
};

