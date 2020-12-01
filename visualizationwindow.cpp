#include "visualizationwindow.h"


VisualizationWindow::VisualizationWindow(int rows, int columns, QWidget* parent) // TODO: add n.
  : QWidget(parent)
{
  setWindowTitle("Визуализация алгоритма");

  // Создаём layout, на который будем помещать таблицу.
  QHBoxLayout *layout = new QHBoxLayout(this);

  // TODO: Создаём саму таблицу с заданным количеством рядов и колонок.

  // TODO: Считаем размерность таблицы.



  QTableWidget *table = new QTableWidget(rows, columns, this);
  table->setEditTriggers(0); // Запрещаем редактирование ячеек таблицы.
  // Скрываем header-ы таблицы.
  table->horizontalHeader()->setVisible(false);
  table->verticalHeader()->hide();

  // Добавляем таблицу на layout формы.
  layout->addWidget(table);


  // Заполняем таблицу числами от 1 до заданного n.
  QTableWidgetItem* item;
  uint number = 0;
  for (int row = 0; row < table->rowCount(); ++row) {
    for (int column = 0; column < table->columnCount(); ++column) {
      item = new QTableWidgetItem(QString::number(++number));
      // TODO: if (number == n) break;
      table->setItem(row, column, item);
    }
  }
  // Изменяем размеры ячеек под содержимое таблицы.
  table->resizeColumnsToContents();
  table->resizeRowsToContents();

}
