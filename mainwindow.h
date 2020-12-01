#pragma once

#include "myMaths.h"
#include "visualizationwindow.h"

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void on_buttonPrime_clicked();
  void on_buttonPerfect_clicked();

private:
  void checkPerfect();
  void checkPrime();

  QStringList primeActions;
  QStringList perfectActions;

  VisualizationWindow *visualizationWindow;
  Ui::MainWindow *ui;
};
