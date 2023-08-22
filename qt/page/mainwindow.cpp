#include "mainwindow.h"

#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      pages(new QStackedWidget(this)),
      nextBtn(new QPushButton("Next", this)),
      prevBtn(new QPushButton("Previous", this)) {
  QWidget *page1 = new QWidget(this);
  page1->setStyleSheet("background-color: red;");

  QLabel *label1 = new QLabel("This is Page 1", page1);
  label1->setAlignment(Qt::AlignCenter);
  label1->setGeometry(50, 50, 200, 50);  // adjust as needed
  label1->setStyleSheet("color: white;");

  QWidget *page2 = new QWidget(this);
  page2->setStyleSheet("background-color: blue;");

  QLabel *label2 = new QLabel("This is Page 2", page2);
  label2->setAlignment(Qt::AlignCenter);
  label2->setGeometry(50, 50, 200, 50);  // adjust as needed
  label2->setStyleSheet("color: white;");

  QWidget *page3 = new QWidget(this);
  page3->setStyleSheet("background-color: green;");

  QLabel *label3 = new QLabel("This is Page 3", page3);
  label3->setAlignment(Qt::AlignCenter);
  label3->setGeometry(50, 50, 200, 50);  // adjust as needed
  label3->setStyleSheet("color: white;");

  pages->addWidget(page1);
  pages->addWidget(page2);
  pages->addWidget(page3);

  prevBtn->setGeometry(50, 15, 100, 30);
  nextBtn->setGeometry(170, 15, 100, 30);

  connect(nextBtn, &QPushButton::clicked, this, &MainWindow::nextPage);
  connect(prevBtn, &QPushButton::clicked, this, &MainWindow::prevPage);

  setCentralWidget(pages);

  connect(pages, &QStackedWidget::currentChanged, this, &MainWindow::updateButtons);
  updateButtons();

  resize(400, 300);
}

void MainWindow::nextPage() {
  int currentIndex = pages->currentIndex();
  if (currentIndex < pages->count() - 1) {
    pages->setCurrentIndex(currentIndex + 1);
  }
}

void MainWindow::prevPage() {
  int currentIndex = pages->currentIndex();
  if (currentIndex > 0) {
    pages->setCurrentIndex(currentIndex - 1);
  }
}

void MainWindow::updateButtons() {
  int currentIndex = pages->currentIndex();

  nextBtn->setVisible(currentIndex != pages->count() - 1);
  prevBtn->setVisible(currentIndex != 0);
}
