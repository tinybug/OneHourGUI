#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QHBoxLayout>
#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  QPushButton *tabButton1;
  QPushButton *tabButton2;
  QPushButton *tabButton3;
  QStackedWidget *stackedWidget;
  QHBoxLayout *tabsLayout;
};

#endif  // MAINWINDOW_H
