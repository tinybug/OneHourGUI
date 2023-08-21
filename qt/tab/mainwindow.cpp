#include "mainwindow.h"

#include <QLabel>
#include <QStyle>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  QWidget *centralWidget = new QWidget(this);
  QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

  // Horizontal layout for the tab buttons
  tabsLayout = new QHBoxLayout();
  tabsLayout->setSpacing(0);

  tabButton1 = new QPushButton("Tab 1", this);
  tabButton2 = new QPushButton("Tab 2", this);
  tabButton3 = new QPushButton("Tab 3", this);

  tabButton1->setFixedWidth(100);  // For example, 100 pixels
  tabButton2->setFixedWidth(100);
  tabButton3->setFixedWidth(100);

  QString firstTabStyle =
      "QPushButton {"
      "   border-top: 1px solid #999;"
      "   border-left: 1px solid #999;"
      "   border-right: 1px solid #999;"
      "   border-bottom: 1px solid #999;"
      "   padding: 5px 15px;"
      "   background: #ddd;"
      "   margin: 0px;"
      "}"
      "QPushButton:checked {"
      "   background: #fff;"
      "   border-bottom: 1px solid #fff;"
      "}";

  tabButton1->setStyleSheet(firstTabStyle);

  QString tabStyle =
      "QPushButton {"
      "   border-top: 1px solid #999;"
      "   border-right: 1px solid #999;"
      "   border-bottom: 1px solid #999;"
      "   padding: 5px 15px;"
      "   background: #ddd;"
      "   margin: 0px;"
      "}"
      "QPushButton:checked {"
      "   background: #fff;"
      "   border-bottom: 1px solid #fff;"
      "}"
      "QPushButton:first-child {"
      "   border-left: 1px solid #999;"
      "}";

  tabButton1->setCheckable(true);
  tabButton2->setCheckable(true);
  tabButton3->setCheckable(true);

  tabButton2->setStyleSheet(tabStyle);
  tabButton3->setStyleSheet(tabStyle);

  connect(tabButton1, &QPushButton::clicked, [=]() {
    tabButton1->setChecked(true);
    tabButton2->setChecked(false);
    tabButton3->setChecked(false);
    stackedWidget->setCurrentIndex(0);
  });

  connect(tabButton2, &QPushButton::clicked, [=]() {
    tabButton2->setChecked(true);
    tabButton1->setChecked(false);
    tabButton3->setChecked(false);
    stackedWidget->setCurrentIndex(1);
  });

  connect(tabButton3, &QPushButton::clicked, [=]() {
    tabButton1->setChecked(false);
    tabButton2->setChecked(false);
    tabButton3->setChecked(true);
    stackedWidget->setCurrentIndex(2);
  });

  tabsLayout->addWidget(tabButton1);
  tabsLayout->addWidget(tabButton2);
  tabsLayout->addWidget(tabButton3);

  // Add a spacer to push the tabs to the left
  QSpacerItem *horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
  tabsLayout->addSpacerItem(horizontalSpacer);

  stackedWidget = new QStackedWidget(this);
  stackedWidget->addWidget(new QLabel("Content of Tab 1"));
  stackedWidget->addWidget(new QLabel("Content of Tab 2"));
  stackedWidget->addWidget(new QLabel("Content of Tab 3"));

  mainLayout->addLayout(tabsLayout);
  mainLayout->addWidget(stackedWidget);

  centralWidget->setLayout(mainLayout);

  setCentralWidget(centralWidget);
  tabButton1->click();  // To show first tab as default

  resize(400, 300);
}

MainWindow::~MainWindow() {}
