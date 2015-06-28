#include "Nineblock.h"

NineBlock::NineBlock()
{

}

NineBlock::~NineBlock()
{

}

int NineBlock::condition(Blank *a[10][10], Blank *center)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    if(num<10)
    {
        //L shape below
        if(R>=2 && C>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                &&(num==a[R][C-2]->number||num==a[R][C-2]->number%10))  {return 1;} // _|
        if(R>=2 && C<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R][C+2]->number||num==a[R][C+2]->number%10))  {return 2;} // L
        if(R<=7 && C<=7 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 3;} // |-
        if(R<=7 && C>=2 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 4;} // -|
        // T shape below
        if(C>=2 && R<=8 && R>=1 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10))  {return 5;} // -|
        if(R>=2 && C<=8 && C>=1 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R-2][C]->number||num==a[R-2][C]->number%10))  {return 6;} // UPsidedown T
        if(R>=1 && C<=7 && R<=8 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10))  {return 7;} // |-
        if(R<=7 && C>=1 && C<=8 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 8;} // T
    }
    else if(num>10)
    {
        num=num%10;
        if(R>=2 && C>=2 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10))  {return 9;} // _|
        if(R>=2 && C<=7 && (num==a[R-2][C]->number||num==a[R-2][C]->number%10)
                && (num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R][C+2]->number||num==a[R][C+2]->number%10))  {return 10;} // L
        if(R<=7 && C<=7 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 11;} // |-
        if(R<=7 && C<=2 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 12;} // -|
        // T shape below
        if(R>=1 && R<=8 && C>=2 && (num==a[R][C-2]->number||num==a[R][C-2]->number%10)
                && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10))  {return 13;} // -|
        if(R>=2 && C<=8 && C>=1 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R-2][C]->number||num==a[R-2][C]->number%10))  {return 14;} // UPsidedown T
        if(R>=1 && C<=7 && R>=8 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R-1][C]->number||num==a[R-1][C]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10))  {return 15;} // |-
        if(R<=7 && C>=1 && C<=8 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10)
                && (num==a[R][C+1]->number||num==a[R][C+1]->number%10)
                &&(num==a[R+1][C]->number||num==a[R+1][C]->number%10)
                &&(num==a[R+2][C]->number||num==a[R+2][C]->number%10))  {return 16;} // T
    }
    return 0;
}

void NineBlock::spawn(Blank*a[10][10],Blank * center,int mode)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    int FiveNum[5]={0}; //0=basis candy
    int color=0;//store color
    switch (mode) {
    case 1:
        color=center->number%10;
        center->number=30+color; //give center vertical

        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=center->number; //center candy is chocolate
        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R+1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R+2][C]->number/10;
        }

        for (int j=0;j<3;j++)
         {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C-2+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            }
        }
        for (int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;
    case 2:
        color=center->number%10;
        center->number=30+color;



        if(a[R][C+2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C+2]->number/10;
        }

        if(a[R][C+1]->number>10)
        {
            FiveNum[1]=a[R][C+1]->number/10;
        }
        FiveNum[2]=center->number;


        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R-1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R-2][C]->number/10;
        }

        for (int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C+2-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            }
        }
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;

    case 3:
        color=center->number%10;
        center->number=30+color;

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)
        {
            FiveNum[1]=a[R+1][C]->number/10;
        }
        FiveNum[2]=center->number; //center candy is chocolate
        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[4]=a[R][C+2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C+1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            }
        }
        break;

    case 4:
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[1]=a[R+1][C]->number/10;
        }

        FiveNum[2]=center->number;

        if(a[R][C-1]->number>10)
        {
            FiveNum[3]=a[R][C-1]->number/10;
        }

        if(a[R][C-2]->number>10)
        {
            FiveNum[4]=a[R][C-2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C-1-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            }
        }
        break;
    case 5:
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-1][C]->number/10;
        }
        FiveNum[1]=center->number;

        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[2]=a[R+1][C]->number/10;
        }

        if(a[R][C-1]->number>10)
        {
            FiveNum[3]=a[R][C-1]->number/10;
        }

        if(a[R][C-2]->number>10)
        {
            FiveNum[4]=a[R][C-2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C-1-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            }
        }
        break;

    case 6:
        color=center->number%10;
        center->number=30+color;



        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-1]->number/10;
        }

        FiveNum[1]=center->number;

        if(a[R][C+1]->number>10)
        {
            FiveNum[2]=a[R][C+1]->number/10;
        }

        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R-1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R-2][C]->number/10;
        }

        for (int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C-1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            }
        }
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;
    case 7:
        color=center->number%10;
        center->number=30+color;

        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-1][C]->number/10;
        }

        FiveNum[1]=center->number; //center candy is chocolate

        if(a[R+1][C]->number>10)
        {
            FiveNum[2]=a[R+1][C]->number/10;
        }
        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[4]=a[R][C+2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C+1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            }
        }
        break;
    case 8:
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[1]=a[R+1][C]->number/10;
        }

        if(a[R][C-1]->number>10)
        {
            FiveNum[2]=a[R][C-1]->number/10;
        }
        FiveNum[3]=center->number;

        if(a[R][C+1]->number>10)
        {
            FiveNum[4]=a[R][C+1]->number/10;
        }

        for (int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j+2])
            {
            case 0:  // basis candy
                a[R][C-1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            }
        }
        break;
    case 9:
        num=num%10;
        color=center->number%10;
        center->number=30+color; //give center vertical

        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            FiveNum[1]=a[R][C-1]->number/10;
        }
        FiveNum[2]=a[R][C]->number/10; //center candy is chocolate
        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R+1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R+2][C]->number/10;
        }

        for (int j=0;j<3;j++)
         {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C-2+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-2+j]);
                delete d;
                break;
            }
        }
        for (int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;
    case 10:
        num=num%10;
        color=center->number%10;
        center->number=30+color;



        if(a[R][C+2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C+2]->number/10;
        }

        if(a[R][C+1]->number>10)
        {
            FiveNum[1]=a[R][C+1]->number/10;
        }
        FiveNum[2]=a[R][C]->number/10;


        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R-1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R-2][C]->number/10;
        }

        for (int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C+2-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+2-j]);
                delete d;
                break;
            }
        }
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;

    case 11:
        num=num%10;
        color=center->number%10;
        center->number=30+color;

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)
        {
            FiveNum[1]=a[R+1][C]->number/10;
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

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C+1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            }
        }
        break;

    case 12:
        num=num%10;
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[1]=a[R+1][C]->number/10;
        }

        FiveNum[2]=a[R][C]->number/10;

        if(a[R][C-1]->number>10)
        {
            FiveNum[3]=a[R][C-1]->number/10;
        }

        if(a[R][C-2]->number>10)
        {
            FiveNum[4]=a[R][C-2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C-1-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            }
        }
        break;
    case 13:
        num=num%10;
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-1][C]->number/10;
        }
        FiveNum[1]=a[R][C]->number/10;

        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[2]=a[R+1][C]->number/10;
        }

        if(a[R][C-1]->number>10)
        {
            FiveNum[3]=a[R][C-1]->number/10;
        }

        if(a[R][C-2]->number>10)
        {
            FiveNum[4]=a[R][C-2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C-1-j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1-j]);
                delete d;
                break;
            }
        }
        break;

    case 14:
        num=num%10;
        color=center->number%10;
        center->number=30+color;



        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R][C-1]->number/10;
        }

        FiveNum[1]=a[R][C]->number/10;

        if(a[R][C+1]->number>10)
        {
            FiveNum[2]=a[R][C+1]->number/10;
        }

        if(a[R-1][C]->number>10)
        {
            FiveNum[3]=a[R-1][C]->number/10;
        }
        if(a[R-2][C]->number>10)
        {
            FiveNum[4]=a[R-2][C]->number/10;
        }

        for (int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j])
            {
            case 0:  // basis candy
                a[R][C-1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            }
        }
        for(int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i+3])
            {
            case 0:  // basis candy
                a[R-i-1][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-i-1][C]);
                delete d;
                break;
            }
        }
        break;
    case 15:
        num=num%10;
        color=center->number%10;
        center->number=30+color;

        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R-1][C]->number/10;
        }

        FiveNum[1]=a[R][C]->number/10; //center candy is chocolate

        if(a[R+1][C]->number>10)
        {
            FiveNum[2]=a[R+1][C]->number/10;
        }
        if(a[R][C+1]->number>10)
        {
            FiveNum[3]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            FiveNum[4]=a[R][C+2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R-1+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R-1+i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<2;j++)
        {
            Destroy *d;
            switch(FiveNum[j+3])
            {
            case 0:  // basis candy
                a[R][C+1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+1+j]);
                delete d;
                break;
            }
        }
        break;
    case 16:

        num=num%10;
        color=center->number%10;
        center->number=30+color; //T shape

        if(a[R+2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[0]=a[R+2][C]->number/10;
        }
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            FiveNum[1]=a[R+1][C]->number/10;
        }

        if(a[R][C-1]->number>10)
        {
            FiveNum[2]=a[R][C-1]->number/10;
        }
        FiveNum[3]=a[R][C]->number/10;

        if(a[R][C+1]->number>10)
        {
            FiveNum[4]=a[R][C+1]->number/10;
        }

        for (int i=0;i<2;i++)
        {
            Destroy *d;
            switch(FiveNum[i])
            {
            case 0:  // basis candy
                a[R+2-i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+2-i][C]);
                delete d;
                break;
            }
        }
        for(int j=0;j<3;j++)
        {
            Destroy *d;
            switch(FiveNum[j+2])
            {
            case 0:  // basis candy
                a[R][C-1+j]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C-1+j]);
                delete d;
                break;
            }
        }
        break;
    }
}




void NineBlock::eliminate(Blank *a[10][10], Blank *center)
{
    int R=center->row;
    int C=center->column;
    center->number=0;
    int EightNum[8]={0};
    if(R>=1 && C>=1 && a[R-1][C-1]->number%10!=0)
    {
        EightNum[0]=a[R-1][C-1]->number/10;
    }
    if(R>=1 && a[R-1][C]->number%10!=0)
    {
        EightNum[1]=a[R-1][C]->number/10;
    }
    if(R>=1 && C<=8 && a[R-1][C+1]->number%10!=0)
    {
        EightNum[2]=a[R-1][C+1]->number/10;
    }
    if(C>=1 && a[R][C-1]->number%10!=0)
    {
        EightNum[3]=a[R][C-1]->number/10;
    }
    if(C<=8 && a[R][C+1]->number%10!=0)
    {
        EightNum[4]=a[R][C+1]->number/10;
    }
    if(C>=1 && R<=8 && a[R+1][C-1]->number%10!=0)
    {
        EightNum[5]=a[R+1][C-1]->number/10;
    }
    if(R<=8 && a[R+1][C]->number%10!=0)
    {
        EightNum[6]=a[R+1][C]->number/10;
    }
    if(R<=8 && C<=8 && a[R+1][C+1]->number%10!=0)
    {
        EightNum[7]=a[R+1][C+1]->number/10;
    }

    Destroy *d;
    int color=0;
    if (R>=1&& C>=1)
    {
        switch (EightNum[0]) {
        case 0:
            a[R-1][C-1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R-1][C-1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R-1][C-1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R-1][C-1]);
          delete d;
          break;
        }
    }
    if (R>=1)
    {
        switch (EightNum[1]) {
        case 0:
            a[R-1][C]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R-1][C]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R-1][C]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R-1][C]);
          delete d;
          break;
        }
    }
    if (R>=1&& C<=8)
    {
        switch (EightNum[2]) {
        case 0:
            a[R-1][C+1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R-1][C+1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R-1][C+1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R-1][C+1]);
          delete d;
          break;
        }
    }
    if (C>=1)
    {
        switch (EightNum[3]) {
        case 0:
            a[R][C-1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R][C-1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R][C-1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R][C-1]);
          delete d;
          break;
        }
    }
    if (C<=8)
    {
        switch (EightNum[4]) {
        case 0:
            a[R][C+1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R][C+1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R][C+1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R][C+1]);
          delete d;
          break;
        }
    }
    if (C>=1 && R<=8)
    {
        switch (EightNum[5]) {
        case 0:
            a[R+1][C-1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R+1][C-1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R+1][C-1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R+1][C-1]);
          delete d;
          break;
        }
    }
    if (R<=8)
    {
        switch (EightNum[6]) {
        case 0:
            a[R+1][C]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R+1][C]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R+1][C]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R+1][C]);
          delete d;
          break;
        }
    }
    if (R<=8 && C<=8)
    {
        switch (EightNum[7]) {
        case 0:
            a[R+1][C+1]->number=0;
            break;
        case 1:
          d= new Vertical;
          d->eliminate(a,a[R+1][C+1]);
          delete d;
          break;
        case 2:
          d=new Horizontal;
          d->eliminate(a,a[R+1][C+1]);
          delete d;
          break;
        case 3:
          d= new NineBlock;
          d->eliminate(a,a[R+1][C+1]);
          delete d;
          break;
        }
    }
}
