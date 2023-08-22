// CountdownWindow.h
#ifndef COUNTDOWNWINDOW_H
#define COUNTDOWNWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QTimer>

class CountdownWindow : public QMainWindow {
  Q_OBJECT

 public:
  CountdownWindow();

 private:
  QLabel *countdownLabel;
  int m_remainingSeconds;
  QTimer *timer;
};

#endif  // COUNTDOWNWINDOW_H
