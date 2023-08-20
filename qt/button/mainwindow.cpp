#include "mainwindow.h"

#include <QHBoxLayout>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow() {
  QWidget *centralWidget = new QWidget(this);

  QPushButton *centerButton = new QPushButton("Hello, Qt6!", this);

  QPushButton *leftButton = new QPushButton("Left", centralWidget);
  QPushButton *right1Button = new QPushButton("Right 1", centralWidget);
  QPushButton *right2Button = new QPushButton("Right 2", centralWidget);

  QHBoxLayout *bottomLayout = new QHBoxLayout();
  bottomLayout->addWidget(leftButton);
  bottomLayout->addStretch(1);
  bottomLayout->addWidget(right1Button);
  bottomLayout->addWidget(right2Button);

  QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
  mainLayout->addWidget(centerButton, 0, Qt::AlignCenter);
  mainLayout->addLayout(bottomLayout);

  centralWidget->setLayout(mainLayout);

  setCentralWidget(centralWidget);
  resize(400, 300);
}
