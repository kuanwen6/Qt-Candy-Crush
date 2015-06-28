#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "blank.h"
#include "Star.h"
#include "Destroy.h"
#include "Nineblock.h"
#include "Horizontal.h"
#include "Vertical.h"
#include "Three.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void GameStart();
    void setClickedPicture(Blank *b);
    bool Judge(int row1, int column1, int row2, int column2);
    bool JudgeStar(int R, int C);
    bool JudgeVertical(int R, int C);
    bool JudgeNineBlock(int R,int C);
    bool JudgeHorizontal(int R,int C);
    bool JudgeThree(int R,int C);
    void RenewPicture();
    void Dropdown();
    void RandNum();
    void WinGame();
    void GameOver();
    void DropRemove();
    bool CanRemove();
    bool Starbomb(int row1, int column1, int row2, int column2);
    void Restart();
    ~MainWindow();

public slots:
    void button_clicked(int R,int C);

signals:
    void quit(int star,int score);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Blank * b[10][10];
    int record_R;
    int record_C;
    bool isClicked;
    Destroy *destroy;
    int score;
    int step=20;
    int star=0;
};

#endif // MAINWINDOW_H
