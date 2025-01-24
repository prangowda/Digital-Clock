#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QVBoxLayout>

class DigitalClock : public QMainWindow {
    Q_OBJECT

public:
    DigitalClock(QWidget *parent = nullptr);
    ~DigitalClock();

private slots:
    void updateTime();

private:
    QLabel *clockLabel;
    QTimer *timer;
};

#endif // DIGITALCLOCK_H
