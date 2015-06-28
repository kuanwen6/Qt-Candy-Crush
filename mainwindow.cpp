#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            b[i][j]= new Blank (this,i,j);
            connect(b[i][j],SIGNAL(Click(int,int)),this,SLOT(button_clicked(int,int)));
        }
    }
    score=0;
    QString a,b;
    a=QString::number(score,10);
    b=QString::number(step,10);
    ui->score->setText(a);
    ui->step->setText(b);
    ui->win->setText("");
}

void MainWindow::GameStart()
{
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            b[i][j] -> setRandomNumber();
            b[i][j] -> setButtonPicture();
            if(j>=2 && b[i][j]->number==b[i][j-1]->number && b[i][j]->number==b[i][j-2]->number) //if initial map wrong
            {
                j--;  // reset the position
            }
            if(i>=2 && b[i][j]->number==b[i-1][j]->number && b[i-1][j]->number==b[i-2][j]->number)
            {
                j--;
            }
        }
    }
    isClicked=false;
}

void MainWindow::setClickedPicture(Blank *a)
{
    if(!isClicked)
    {
        switch (a->number)
        {
        case 1:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/red_clicked.png")));
          break;
        case 2:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_clicked.png")));
          break;
        case 3:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_clicked.png")));
          break;
        case 4:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_clicked.png")));
          break;
        case 5:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/green_clicked.png")));
          break;
        case 11:  // |
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/red_horizontal_bomb_clicked.png")));
          break;
        case 12:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_horizontal_bomb_clicked.png")));
          break;
        case 13:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_horizontal_bomb_clicked.png")));
          break;
        case 14:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_horizontal_bomb_clicked.png")));
          break;
        case 15:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/green_horizontal_bomb_clicked.png")));
          break;
        case 21:  // -
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/red_vertical_bomb_clicked.png")));
          break;
        case 22:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_vertical_bomb_clicked.png")));
          break;
        case 23:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_vertical_bomb_clicked.png")));
          break;
        case 24:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_vertical_bomb_clicked.png")));
          break;
        case 25:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/green_vertical_bomb_clicked.png")));
          break;
        case 31:  // +
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/red_bomb_clicked.png")));
          break;
        case 32:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/orange_bomb_clicked.png")));
          break;
        case 33:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/blue_bomb_clicked.png")));
          break;
        case 34:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/purple_bomb_clicked.png")));
          break;
        case 35:
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/green_bomb_clicked.png")));
          break;
        case 9:  //chocolate
          a->button->setIcon(QIcon(QPixmap(":/new/prefix1/power_bomb_clicked.png")));
          break;
        default:
          a->button->setIcon(QIcon(QPixmap("nopicture")));
          break;
        }
    }
    else
    {
        a->setButtonPicture();
    }
    a->button->setIconSize(a->button->size());

}

bool MainWindow::Judge(int row1, int column1, int row2, int column2)
{

    bool A[11]={0};
    A[0]=Starbomb(row1,column1,row2,column2);
    A[1]=JudgeStar(row1,column1);
    A[2]=JudgeStar(row2,column2);
    A[3]=JudgeNineBlock(row1,column1);
    A[4]=JudgeNineBlock(row2,column2);
    A[5]=JudgeVertical(row1,column1);
    A[6]=JudgeVertical(row2,column2);
    A[7]=JudgeHorizontal(row1,column1);
    A[8]=JudgeHorizontal(row2,column2);
    A[9]=JudgeThree(row1,column1);
    A[10]=JudgeThree(row2,column2);


    Dropdown();
    RandNum();
    while(CanRemove())
    {
        DropRemove();
        Dropdown();
        RandNum();
    }

    for(int j=0;j<11;j++)
    {
        if(A[j])
        {
            score+=50;
        }
    }
    if(A[0] || A[1] || A[2] || A[3] || A[4] || A[5] || A[6] || A[7] || A[8] || A[9])
    {
        step--;
    }
    QString a,b;
    a=QString::number(score,10);
    b=QString::number(step,10);
    ui->score->setText(a);
    ui->step->setText(b);
    GameOver();
    RenewPicture();
    for(int i=0;i<11;i++)
    {
        if(A[i])
        {
           return true;
        }
    }
    return false;

}

bool MainWindow::JudgeStar(int R, int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy = new Star;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value>0)
    {
        switch (return_value) {
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        }
    }
    else
    {
        return false;
    }
    delete destroy;
    return true;

}

bool MainWindow::JudgeVertical(int R, int C)
{

    int return_value;
    bool AnySpawn=false;
    destroy = new Vertical;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value>0)
    {
        switch (return_value) {

        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        }
    }
    else
    {
        return false;
    }
    delete destroy;
    return true;

}

bool MainWindow::JudgeNineBlock(int R, int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy = new NineBlock;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value>0)
    {
        switch (return_value) {
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        case 5:
            destroy->spawn(b,b[R][C],5);
            AnySpawn=true;
            break;
        case 6:
            destroy->spawn(b,b[R][C],6);
            AnySpawn=true;
            break;
        case 7:
            destroy->spawn(b,b[R][C],7);
            AnySpawn=true;
            break;
        case 8:
            destroy->spawn(b,b[R][C],8);
            AnySpawn=true;
            break;
        case 9:
            destroy->spawn(b,b[R][C],9);
            AnySpawn=true;
            break;
        case 10:
            destroy->spawn(b,b[R][C],10);
            AnySpawn=true;
            break;
        case 11:
            destroy->spawn(b,b[R][C],11);
            AnySpawn=true;
            break;
        case 12:
            destroy->spawn(b,b[R][C],12);
            AnySpawn=true;
            break;
        case 13:
            destroy->spawn(b,b[R][C],13);
            AnySpawn=true;
            break;
        case 14:
            destroy->spawn(b,b[R][C],14);
            AnySpawn=true;
            break;
        case 15:
            destroy->spawn(b,b[R][C],15);
            AnySpawn=true;
            break;
        case 16:
            destroy->spawn(b,b[R][C],16);
            AnySpawn=true;
            break;
        }
    }
    else
    {
        return false;
    }
    delete destroy;
        return true;
}

bool MainWindow::JudgeHorizontal(int R, int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy = new Horizontal;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value>0)
    {
        switch (return_value) {
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        }
    }
    else
    {
        return false;
    }
    delete destroy;

        return true;

}

bool MainWindow::JudgeThree(int R, int C)
{
    int return_value;
    bool AnySpawn=false;
    destroy = new Three;
    return_value=destroy->condition(b,b[R][C]);
    if(return_value>0)
    {
        switch (return_value) {
        case 1:
            destroy->spawn(b,b[R][C],1);
            AnySpawn=true;
            break;
        case 2:
            destroy->spawn(b,b[R][C],2);
            AnySpawn=true;
            break;
        case 3:
            destroy->spawn(b,b[R][C],3);
            AnySpawn=true;
            break;
        case 4:
            destroy->spawn(b,b[R][C],4);
            AnySpawn=true;
            break;
        case 5:
            destroy->spawn(b,b[R][C],5);
            AnySpawn=true;
            break;
        case 6:
            destroy->spawn(b,b[R][C],6);
            AnySpawn=true;
            break;
        case 7:
            destroy->spawn(b,b[R][C],7);
            AnySpawn=true;
            break;
        case 8:
            destroy->spawn(b,b[R][C],8);
            AnySpawn=true;
            break;
        case 9:
            destroy->spawn(b,b[R][C],9);
            AnySpawn=true;
            break;
        case 10:
            destroy->spawn(b,b[R][C],10);
            AnySpawn=true;
            break;
        case 11:
            destroy->spawn(b,b[R][C],11);
            AnySpawn=true;
            break;
        case 12:
            destroy->spawn(b,b[R][C],12);
            AnySpawn=true;
            break;
        }
    }
    else
    {
        return false;
    }
    delete destroy;

        return true;

}

void MainWindow::RenewPicture()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            b[i][j]->setButtonPicture();
        }
    }
}

void MainWindow::Dropdown()
{
    for (int j=0;j<10;j++)
        {
           for(int y=8;y>=0;y--) //fix 0
           {
               if(b[y][j]->number!=0)
               {
                   for(int a=9;a>y;a--)
                   {
                       if(b[a][j]->number==0)
                       {
                          *b[a][j]-b[y][j];
                       }
                   }
               }
           }
    }
}

void MainWindow::RandNum()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            if(b[i][j]->number==0)
            {
                b[i][j]->number=rand()%5+1;
            }
        }
    }
}

void MainWindow::WinGame()
{
    if(score>=2500&& score<2800)
    {
        star=1;
        ui->win->setText("1 Star!");
    }
    else if(score>=2800 && score <3100)
    {
        star=2;
        ui->win->setText("2 Star!");
    }
    else if(score>=3100)
    {
        star=3;
        ui->win->setText("3 Star!");
    }
}

void MainWindow::GameOver()
{
    if(step==0)
    {
        WinGame();
        if(score<2500)
        {
            star=0;
            ui->win->setText("GameOver!");
        }
        emit quit(star,score);
    }
}

void MainWindow::DropRemove()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<=7;j++)
        {
            if(b[i][j]->number!=0&&b[i][j]->number==b[i][j+1]->number&&b[i][j]->number==b[i][j+2]->number)
            {
                b[i][j]->number=0;
                b[i][j+1]->number=0;
                b[i][j+2]->number=0;
                score+=50;
            }
        }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<=7;i++)
        {
            if(b[i][j]->number!=0&&b[i][j]->number%10==b[i+1][j]->number%10&&b[i][j]->number%10==b[i+2][j]->number%10)
            {
                b[i][j]->number=0;
                b[i+1][j]->number=0;
                b[i+2][j]->number=0;
                score+=50;
            }
        }
    }
}

bool MainWindow::CanRemove()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<=7;j++)
        {
            if(b[i][j]->number!=0&&b[i][j]->number%10==b[i][j+1]->number%10&&b[i][j]->number%10==b[i][j+2]->number%10)
            {
               return true;
            }
        }
    }
    for(int j=0;j<10;j++)
    {
        for(int i=0;i<=7;i++)
        {
            if(b[i][j]->number!=0&&b[i][j]->number==b[i+1][j]->number&&b[i][j]->number==b[i+2][j]->number)
            {
                return true;
            }
        }
    }
    return false;
}

bool MainWindow::Starbomb(int row1,int column1, int row2,int column2)
{
    int color;
    if(b[row1][column1]-> number==9)
    {
        color=b[row2][column2]->number%10;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(b[i][j]->number%10==color&&b[i][j]->number!=0)
                {
                    b[i][j]->number=0;
                }
            }
        }
        b[row1][column1]->number=0;
        return true;
    }
    if(b[row2][column2]-> number==9)
    {
        color=b[row1][column1]->number%10;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(b[i][j]->number%10==color&&b[i][j]->number!=0)
                {
                    b[i][j]->number=0;
                }
            }
        }
        b[row2][column2]->number=0;
        return true;
    }
    return false;
}

void MainWindow::Restart()
{
    score=0;
    step=20;
    QString a,b;
    a=QString::number(score,10);
    b=QString::number(step,10);
    ui->score->setText(a);
    ui->step->setText(b);
    ui->win->setText("");
}

MainWindow::~MainWindow()
{
    //emit(score->GetScore(),star->GetStar());
    delete ui;
}

void MainWindow::button_clicked(int R, int C)
{
    if(!isClicked)
    {
        setClickedPicture(b[R][C]);
        record_C = C;
        record_R = R;
        isClicked = true;
    }
    else
    {
        if((record_R-R)*(record_R-R) + (record_C-C)*(record_C-C)==1) //distance==1
        {
            *b[record_R][record_C]-b[R][C];
            if(!Judge(record_R,record_C,R,C))
            {
               *b[record_R][record_C]-b[R][C];
            }

        }
        else // cannot move
        {
            setClickedPicture(b[record_R][record_C]);
        }
        isClicked=false;
    }
}




void MainWindow::on_pushButton_clicked()
{
    for(int i=0;i<10;i++)
    {
        for (int j=0;j<10;j++)
        {
            b[i][j]->number=rand()%5+1;
        }
    }
    while(CanRemove())
    {
        DropRemove();
        Dropdown();
        RandNum();
    }
    Restart();
    RenewPicture();
}
