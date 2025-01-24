#include "digitalclock.h"
#include <QTime>
#include <QFont>
#include <QStyle>

DigitalClock::DigitalClock(QWidget *parent)
    : QMainWindow(parent) {
    // Set up the clock label
    clockLabel = new QLabel(this);
    clockLabel->setAlignment(Qt::AlignCenter);
    clockLabel->setStyleSheet("font-size: 48px; color: #007BFF; background-color: #F5F5F5; border: 2px solid #007BFF; border-radius: 10px;");
    clockLabel->setFixedSize(300, 100);

    // Set up the timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DigitalClock::updateTime);
    timer->start(1000); // Update every second

    // Call updateTime to display the current time immediately
    updateTime();

    // Set up the main layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(clockLabel);
    setCentralWidget(centralWidget);

    // Set window properties
    setWindowTitle("Digital Clock");
    setFixedSize(320, 150);
    setStyleSheet("background-color: #FFFFFF;");
}

DigitalClock::~DigitalClock() {}

void DigitalClock::updateTime() {
    // Get the current time
    QTime currentTime = QTime::currentTime();

    // Format the time as HH:MM:SS
    QString timeString = currentTime.toString("hh:mm:ss");

    // Update the clock label
    clockLabel->setText(timeString);
}
