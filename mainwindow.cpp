#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace {
  QString primeInfo = "Просто́е число́ — натуральное (целое положительное) число, "
                        "имеющее ровно два различных натуральных делителя — единицу и самого себя. "
                        "Другими словами, число x является простым, если оно больше 1 и при этом делится "
                        "без остатка только на 1 и на x. "
                        "К примеру, 5 — простое число, а 6 не является простым числом, "
                        "так как, помимо 1 и 6, оно также делится на 2 и на 3.";

  QString perfectInfo = "Совершенное число́ — натуральное число, равное сумме всех своих собственных делителей "
                        "(то есть всех положительных делителей, отличных от самого́ числа). По мере того как "
                        "натуральные числа возрастают, совершенные числа встречаются всё реже. "
                        "Неизвестно, бесконечно ли множество всех совершенных чисел.";
}

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  primeActions << "Список простых чисел в диапазоне от 2 до n"
               << "Является ли число n простым"
               << "Информация о простых числах";

  perfectActions << "Список совершенных чисел до n"
                 << "Является ли число n совершенным"
                 << "Информация о совершенных числах";
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_buttonPrime_clicked() {

  bool ok;
  QString item = QInputDialog::getItem(this, "Что хотим сделать?", "Выбор действия: ", primeActions, 1, false, &ok);

  // Если в диалоговом окне выбрали "отмена" или выбор по какой-то причине пустой.
  if (!ok || item.isEmpty()) {
    return;
  }

  switch(primeActions.indexOf(item)) {

    case 0: // Список простых чисел в диапазоне от 2 до n.
      visualizationWindow = new VisualizationWindow(10, 10);
      visualizationWindow->showMaximized();
      break;

    case 1: // Является ли число n простым.
      checkPrime();
      break;

    case 2: // Информация о простых числах.
      QMessageBox::information(0, "Простые числа!", primeInfo);
      break;

    default:
      break;
  }
}

void MainWindow::on_buttonPerfect_clicked() {

  bool ok;
  QString item = QInputDialog::getItem(this, "Что хотим сделать?", "Выбор действия: ", perfectActions, 1, false, &ok);

  // Если в диалоговом окне выбрали "отмена" или выбор по какой-то причине пустой.
  if (!ok || item.isEmpty()){
    return;
  }

  switch(perfectActions.indexOf(item)) {

    case 0: // Список совершенных чисел до n.
      break;

    case 1: // Является ли число n совершенным.
      checkPerfect();
      break;

    case 2: // Информация о совершенных числах.
      QMessageBox::information(0, "Совершенные числа!", perfectInfo);
      break;

    default:
      break;
  }
}

void MainWindow::checkPerfect() {
  bool bOk;
  uint number = QInputDialog::getText(0, "Ввод числа n", "Введите число [1..∞]: ", QLineEdit::Normal, "", &bOk).toUInt();

  if (!bOk)
    return;

  if (number < 1) {
    QMessageBox::warning(0, "Ошибка!", "Вводите число в диапазоне [1..∞]!");
    return;
  }

  QString result;
  if (isPerfect(number))
    result = " является совершенным!";
  else
    result = " не является совершенным!";

  QMessageBox::information(0, "Результат", "Число " + QString::number(number) + result);
}

void MainWindow::checkPrime() {
  bool bOk;
  uint number = QInputDialog::getText(0, "Ввод числа n", "Введите число [2..∞]: ", QLineEdit::Normal, "", &bOk).toUInt();

  if (!bOk)
    return;

  if (number < 2) {
    QMessageBox::warning(0, "Ошибка!", "Вводите число в диапазоне [2..∞]!");
    return;
  }

  QString result;
  if (isPrime(number))
    result = " является простым!";
  else
    result = " не является простым!";

  QMessageBox::information(0, "Результат", "Число " + QString::number(number) + result);
}
