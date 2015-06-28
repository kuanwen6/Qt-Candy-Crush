#ifndef BLANK_H
#define BLANK_H

#include <QPushButton>
#include <QObject>

namespace Ui {
class Blank;
}

class Blank : public QObject
{
    Q_OBJECT

public:
    explicit Blank(QWidget *parent,int R,int C);
    ~Blank();
    QPushButton * button;
    const int row;
    const int column;
    int number;
    void setButtonPicture();
    void setRandomNumber();
    void operator -(Blank *a);
   // void operator +(Blank *a);

public slots:
    void clicked();
signals:
    void Click(int R,int C);

private:
    Ui::Blank *ui;
};

#endif // BLANK_H
