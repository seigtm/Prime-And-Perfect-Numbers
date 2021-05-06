#include "visualizationwindow.h"


VisualizationWindow::VisualizationWindow(const uint n, QWidget* parent)
  : QWidget(parent)
  , n{ n }
{
  setWindowTitle("Визуализация алгоритма");
  // Создаём layout, на который будем помещать элементы интерфейса.
  layout = new QHBoxLayout(this);
  showFullScreen();
}

void VisualizationWindow::calculatePrimes() {

  // Считаем размерность таблицы (по-умолчанию - квадратная).
  tableRows    = static_cast<uint>(qSqrt(n));
  tableColumns = static_cast<uint>(qSqrt(n));
  // Если корень из n выходит неровным.
  if (qSqrt(n) > tableRows) {
    // От греха подальше нарисуем на один ряд и колонку больше.
    tableRows++;
    tableColumns++;
    // (Чтобы все числа точно вместились).
    // На самом деле - не всегда лучшая реализация, но зато простая.
  }

  initTable(); // Создаём таблицу.
  fillTable(); // Заполняем её числами от 2 до n.


  QTableWidgetItem *cell; // Указатель на ячейку в таблице.
  uint currentNumber;     // Число, хранимое в этой ячейке.

  // Проходим циклом по всей таблице.
  uint iEnd{ static_cast<uint>(qSqrt(n) + 1) };
  for (uint i{ 2 }; i < iEnd; ++i) { // Цикл от 2 до корня из n + 1.
    for (int row{}; row < table->rowCount(); ++row) {
      for (int column{}; column < table->columnCount(); ++column) {

        // Если ячейка пустая (в ней не было никакого числа).
        if (!table->item(row, column))
          break;

        cell = table->item(row, column);       // Перемещаем указатель по таблице.
        currentNumber = cell->text().toUInt(); // Достаём из ячейки число.

        // Если остаток от деления числа в ячейке таблицы на текущий i == 0
        //  и само число в ячейке не равно i,
        //   это означает, что число не простое.
        if (currentNumber % i == 0 && currentNumber != i) {
          // Потому мы закрашиваем эту ячейку чёрным цветом.
          cell->setBackground(Qt::black);
        }
      }
    }
    // И сигнализируем пользователю о том, что мы сделали на этом шагу.
    QMessageBox::information(0, "Текущая операция", "Зачёркиваем кратные " + QString::number(i));
    //table->update(); // НЕ ФАКТ ЧТО НУЖНО.
  }
}

void VisualizationWindow::initTable() {

  // Создаём и задаём параметры таблицы.
  table = new QTableWidget(tableRows, tableColumns, this);
  table->setEditTriggers(QAbstractItemView::EditTriggers()); // Запрещаем редактирование ячеек таблицы.
  // Скрываем header-ы таблицы.
  table->horizontalHeader()->hide();
  table->verticalHeader()->hide();

  // Добавляем таблицу на layout формы.
  layout->addWidget(table);
}

void VisualizationWindow::fillTable() {
  // Заполняем таблицу числами от 2 до заданного n.
  QTableWidgetItem* item;
  uint currentNumber{ 2 }; // Начинаем с двойки.
  for (int row{}; row < table->rowCount(); ++row) {
    for (int column{}; column < table->columnCount(); ++column) {

      // Если дошли в процессе заполнения до нашего числа n.
      if (currentNumber > n)
        break; // Прерываем цикл.

      // Заносим в конкретную ячейку новую цифру.
      item = new QTableWidgetItem(QString::number(currentNumber++));
      table->setItem(row, column, item);
    }
  }
  // Изменяем размеры ячеек под содержимое таблицы.
  table->resizeColumnsToContents();
  table->resizeRowsToContents();

  QMessageBox::information(0, "Заполнение таблицы", "Первым делом заполняем таблицу числами от 2 до " + QString::number(n));
}
