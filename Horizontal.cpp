#include "Horizontal.h"

Horizontal::Horizontal()
{

}

Horizontal::~Horizontal()
{

}

int Horizontal::condition(Blank *a[10][10], Blank *center)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    if(num!=0 && num !=9)
    {
        if(num<10)
        {
            if(C>=1 && C<=7 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) &&  (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
            {
                return 1;  // center at second position
            }
            if(C>=2 && C<=8 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) &&  (num==a[R][C-1]->number||num==a[R][C-1]->number%10) && (num==a[R][C+1]->number||num==a[R][C+1]->number%10))
            {
                return 2;  // center at third position
            }
        }
        else if(num>=10)
        {
            num=num%10;
            if(C>=1 && C<=7 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) &&  (num==a[R][C+2]->number||num==a[R][C+2]->number%10))
            {
                 return 3;  // bomb center at third position
            }
            if(C>=2 && C<=8 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10) &&  (num==a[R][C-1]->number||num==a[R][C-1]->number%10) && (num==a[R][C+1]->number||num==a[R][C+1]->number%10))
            {
                 return 4;  // bomb center at sencond position
            }
        }
    }
    return 0; // no Vertical
}

void Horizontal::spawn(Blank*a[10][10],Blank * center,int mode)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    int FiveNum[4]={0}; //0=basis candy
    int color=0;//store color
    switch (mode) {
    case 1:
        color=center->number%10;
        center->number=10+color; //give center vertical

        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-1]->number/10;
        }
        FiveNum[1]=center->number; //center candy is special
        if(a[R][C+1]->number>10)
        {
            FiveNum[2]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[3]=a[R][C+2]->number/10;
        }

        for (int i=0;i<4;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R][C-1+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            }
        }
        break;
    case 2:
        color=center->number%10;
        center->number=20+color;

        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }


        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=center->number;

        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }

        for (int i=0;i<4;i++)
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
        color=center->number%10;
        center->number=10+color; //give center vertical

        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-1]->number/10;
        }
        FiveNum[1]=a[R][C]->number/10; //center candy is special
        if(a[R][C+1]->number>10)
        {
            FiveNum[2]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[3]=a[R][C+2]->number/10;
        }

        for (int i=0;i<4;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R][C-1+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+i]);
                delete d;
                break;
            }
        }
        break;
    case 4:
        num=num%10;
        color=center->number%10;
        center->number=20+color;

        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }


        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=a[R][C]->number/10;

        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }

        for (int i=0;i<4;i++)
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

void Horizontal::eliminate(Blank *a[10][10], Blank *center)
{
    int C=center->column;
    center->number=0;
    int TenNum[10]={0};
    Destroy * d;
    for(int i=0;i<10;i++)
    {
         if(a[i][C]->number>0)
         {
             TenNum[i]=a[i][C]->number/10; //type of colume
         }
    }
    for(int i=0;i<10;i++)
    {
        switch (TenNum[i]) {
        case 0:
          a[i][C]->number=0;
          break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[i][C]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[i][C]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[i][C]);
          delete d;
          break;
       }
    }
}

