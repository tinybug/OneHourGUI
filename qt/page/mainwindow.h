#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void nextPage();
    void prevPage();
    void updateButtons();

private:
    QStackedWidget *pages;
    QPushButton *nextBtn;
    QPushButton *prevBtn;
};

#endif // MAINWINDOW_H
