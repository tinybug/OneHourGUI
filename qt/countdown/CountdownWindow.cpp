// CountdownWindow.cpp
#include "CountdownWindow.h"

#include <QDebug>
#include <QFont>
#include <QFontDatabase>
#include <QVBoxLayout>

CountdownWindow::CountdownWindow() {
  // Main Window Configuration
  setWindowTitle("OneHour");
  setWindowFlag(Qt::WindowStaysOnTopHint);
  setFixedSize(200, 100);

  QWidget *centralWidget = new QWidget(this);
  QVBoxLayout *layout = new QVBoxLayout(centralWidget);
  setCentralWidget(centralWidget);

  // Load a fancy font (You can replace with any font of your choice)
  int fontId = QFontDatabase::addApplicationFont(":/fonts/digital-7.regular.ttf");
  QString fontFamily = QFontDatabase::applicationFontFamilies(fontId).at(0);
  QFont fancyFont(fontFamily, 60);

  // Countdown Label
  countdownLabel = new QLabel("60:00", this);
  countdownLabel->setFont(fancyFont);
  countdownLabel->setAlignment(Qt::AlignCenter);
  layout->addWidget(countdownLabel);

  // Timer logic (set for 10 minutes as an example)
  m_remainingSeconds = 60 * 60;
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, [=]() {
    m_remainingSeconds--;

    if (m_remainingSeconds <= 0) {
      timer->stop();
      m_remainingSeconds = 0;
    }

    int minutes = m_remainingSeconds / 60;
    int seconds = m_remainingSeconds % 60;
    countdownLabel->setText(QString::asprintf("%02d:%02d", minutes, seconds));
  });
  timer->start(1000);
}
