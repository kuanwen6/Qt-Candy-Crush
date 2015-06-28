#include "blank.h"
#include "ui_blank.h"
#include <QObject>
#include <ctime>

Blank::Blank(QWidget *parent,int R,int C) :
    QObject(parent),row(R),column(C)
{
    button = new QPushButton(parent);
    button -> setGeometry(column*50,row*50,50,50);
    connect(button,SIGNAL(clicked()),this,SLOT(clicked()));
    srand(time(NULL));
}

Blank::~Blank()
{

}

void Blank::setButtonPicture()
{
    switch(number)
    {
    case 1:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/red.png")));
      break;
    case 2:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/orange.png")));
      break;
    case 3:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/blue.png")));
      break;
    case 4:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/purple.png")));
      break;
    case 5:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/green.png")));
      break;
    case 11:  // |
      button->setIcon(QIcon(QPixmap(":/new/prefix1/red_horizontal_bomb.png")));
      break;
    case 12:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_horizontal_bomb.png")));
      break;
    case 13:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_horizontal_bomb.png")));
      break;
    case 14:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_horizontal_bomb.png")));
      break;
    case 15:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/green_horizontal_bomb.png")));
      break;
    case 21:  // -
      button->setIcon(QIcon(QPixmap(":/new/prefix1/red_vertical_bomb.png")));
      break;
    case 22:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_vertical_bomb.png")));
      break;
    case 23:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_vertical_bomb.png")));
      break;
    case 24:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_vertical_bomb.png")));
      break;
    case 25:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/green_vertical_bomb.png")));
      break;
    case 31:  // +
      button->setIcon(QIcon(QPixmap(":/new/prefix1/red_bomb.png")));
      break;
    case 32:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_bomb.png")));
      break;
    case 33:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_bomb.png")));
      break;
    case 34:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_bomb.png")));
      break;
    case 35:
      button->setIcon(QIcon(QPixmap(":/new/prefix1/green_bomb.png")));
      break;
    case 9:  //chocolate
      button->setIcon(QIcon(QPixmap(":/new/prefix1/power_bomb.png")));
      break;
    default:
      button->setIcon(QIcon(QPixmap("nopicture")));
      break;
    }
    button->setIconSize(button->size());
}

void Blank::setRandomNumber()
{
   // srand(time(NULL));   initial time all same
    number = rand()%5+1;
}

void Blank::operator -(Blank *a)
{
    int tmp_num=a->number;
    a->number=number;
    number=tmp_num;
    setButtonPicture();
    a->setButtonPicture();
}

void Blank::clicked()
{
    emit Click(row,column);
}

