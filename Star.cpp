#include "Star.h"

Star::Star()
{

}

Star::~Star()
{

}

int Star::condition(Blank *a[10][10], Blank *center)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    if(num!=0 && num !=9)
    {
        if(num<10)
        {
            if(R>=2 && R<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10) &&  (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10) && (num==a[R+2][C]->number||num==a[R+2][C]->number%10))
            {
                return 1;  // | clean
            }
            if(C>=2 && C<=7 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) &&  (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) && (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
            {
                return 2;  // - clean
            }
        }
        else if(num>=10)
        {
            num=num%10;
            if(R>=2 && R<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10) &&  (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10) && (num==a[R+2][C]->number||num==a[R+2][C]->number%10))
            {
                return 3;  // | bomb clean
            }
            if(C>=2 && C<=7 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) &&  (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) && (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
            {
                return 4;  // - bomb clean
            }
        }
    }
    return 0; // no star
}

void Star::eliminate(Blank *a[10][10], Blank *center)
{

}

void Star::spawn(Blank *a[10][10], Blank *center, int mode)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    int FiveNum[5]={0}; //0=basis candy
    switch (mode) {
    case 1:
        center->number=9; //T shape
        if(C>=2 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) && (num==a[R][C-1]->number||num==a[R][C-1]->number%10))
        {
            a[R][C-2]->number=0;
            a[R][C-1]->number=0;
        }
        if(C<=7 && (num==a[R][C+1]->number||num==a[R][C+1]->number%10) && (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
        {
            a[R][C+2]->number=0;
            a[R][C+1]->number=0;
        }
        if(a[R-2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-2][C]->number/10;
        }
        if(a[R-1][C]->number>10)
        {
            FiveNum[1]=a[R-1][C]->number/10;
        }
        FiveNum[2]=9; //center candy is chocolate
        if(a[R+1][C]->number>10)
        {
            FiveNum[3]=a[R+1][C]->number/10;
        }
        if(a[R+2][C]->number>10)
        {
            FiveNum[4]=a[R+2][C]->number/10;
        }

        for (int i=0;i<5;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-2+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;
    case 2:
        center->number=9; //T shape
        if(R>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10) && (num==a[R-1][C]->number||num==a[R-1][C]->number%10))
        {
            a[R-1][C]->number=0;
            a[R-2][C]->number=0;
        }
        if(R<=7 && (num==a[R+1][C]->number||num==a[R+1][C]->number%10) && (num==a[R+2][C]->number||num==a[R+2][C]->number%10))
        {
            a[R+2][C]->number=0;
            a[R+1][C]->number=0;
        }
        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=9; //center candy is chocolate
        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[4]=a[R][C+2]->number/10;
        }

        for (int i=0;i<5;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R][C-2+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        break;

    case 3:
        num=num%10;
        center->number=9; //T shape
        if(C>=2 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) && (num==a[R][C-1]->number||num==a[R][C-1]->number%10))
        {
            a[R][C-2]->number=0;
            a[R][C-1]->number=0;
        }
        if(C<=7 && (num==a[R][C+1]->number||num==a[R][C+1]->number%10) && (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
        {
            a[R][C+2]->number=0;
            a[R][C+1]->number=0;
        }
        if(a[R-2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-2][C]->number/10;
        }
        if(a[R-1][C]->number>10)
        {
            FiveNum[1]=a[R-1][C]->number/10;
        }
        FiveNum[2]=a[R][C]->number/10; //center candy is chocolate
        if(a[R+1][C]->number>10)
        {
            FiveNum[3]=a[R+1][C]->number/10;
        }
        if(a[R+2][C]->number>10)
        {
            FiveNum[4]=a[R+2][C]->number/10;
        }

        for (int i=0;i<5;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-2+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-2+i][C]);
                delete d;
                break;
            }
        }
        break;

    case 4:
        num=num%10;
        center->number=9; //T shape
        if(R>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10) && (num==a[R-1][C]->number||num==a[R-1][C]->number%10))
        {
            a[R-1][C]->number=0;
            a[R-2][C]->number=0;
        }
        if(R<=7 && (num==a[R+1][C]->number||num==a[R+1][C]->number%10) && (num==a[R+2][C]->number||num==a[R+2][C]->number%10))
        {
            a[R+2][C]->number=0;
            a[R+1][C]->number=0;
        }
        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=a[R][C]->number/10; //center candy is chocolate
        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[4]=a[R][C+2]->number/10;
        }

        for (int i=0;i<5;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R][C-2+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+i]);
                delete d;
                break;
            }
        }
        break;
    default:
        break;
    }
}

