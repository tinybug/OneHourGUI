// main.cpp
#include <QApplication>

#include "CountdownWindow.h"

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  CountdownWindow mainWindow;
  mainWindow.show();

  return app.exec();
}
