#include "Three.h"

Three::Three()
{

}

Three::~Three()
{

}

int Three::condition(Blank *a[10][10], Blank *center)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    if(num!=0 && num !=9)
    {
        if(num<10)
        {
            if(C>=1 && C<=8 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) )
            {
                return 1;  // Horizontal
            }
            if(C<=7 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) )
            {
                return 2;
            }
            if(C>=2&&(num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C-2]->number||num==a[R][C-2]->number%10) )
            {
                return 3;
            }
            if(R>=1 && R<=8 && (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10))
            {
                return 4;  // Vertical
            }
            if(R>=2 && (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R-2][C]->number||num==a[R-2][C]->number%10))
            {
                return 5;
            }
            if(R<=7 && (num==a[R+2][C]->number||num==a[R+2][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10))
            {
                return 6;
            }
        }
        else if(num>=10)
        {
            num=num%10;
            if(C>=1 && C<=8 && (num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) )
            {
                return 7;  // Horizontal
            }
            if(C<=7 && (num==a[R][C+2]->number||num==a[R][C+2]->number%10) &&  (num==a[R][C+1]->number||num==a[R][C+1]->number%10) )
            {
                return 8;
            }
            if(C>=2&&(num==a[R][C-1]->number||num==a[R][C-1]->number%10) &&  (num==a[R][C-2]->number||num==a[R][C-2]->number%10) )
            {
                return 9;
            }
            if(R>=1 && R<=8 && (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10))
            {
                return 10;  // Vertical
            }
            if(R>=2 && (num==a[R-1][C]->number||num==a[R-1][C]->number%10) &&  (num==a[R-2][C]->number||num==a[R-2][C]->number%10))
            {
                return 11;
            }
            if(R<=7 && (num==a[R+2][C]->number||num==a[R+2][C]->number%10) &&  (num==a[R+1][C]->number||num==a[R+1][C]->number%10))
            {
                return 12;
            }
        }
    }
    return 0; // no
}

void Three::spawn(Blank *a[10][10], Blank *center, int mode)
{
    int R=center->row;
    int C=center->column;
    int num=center->number;
    int ThreeNum[3]={0}; //0=basis candy
    switch (mode) {
    case 1:
        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R][C-1]->number/10;
        }
        ThreeNum[1]=center->number/10;
        if(a[R][C+1]->number>10)
        {
            ThreeNum[2]=a[R][C+1]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
        ThreeNum[0]=center->number/10;
        if(a[R][C+1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[1]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            ThreeNum[2]=a[R][C+2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
            {
            case 0:  // basis candy
                a[R][C+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            }
        }
        break;
    case 3:
        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            ThreeNum[1]=a[R][C-1]->number/10;
        }
        ThreeNum[2]=center->number/10;

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
    case 4:

        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R-1][C]->number/10;
        }

        ThreeNum[1]=center->number/10;

        if(a[R+1][C]->number>10)
        {
            ThreeNum[2]=a[R+1][C]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
        break;
    case 5:
        if(a[R-2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R-2][C]->number/10;
        }

        if(a[R-1][C]->number>10)
        {
            ThreeNum[1]=a[R-1][C]->number/10;
        }
        ThreeNum[2]=center->number/10;

        for (int i=0;i<3;i++)
        {
            a[R-2+i][C]->number=0;
            Destroy *d;
            switch(ThreeNum[i])
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
    case 6:
        ThreeNum[0]=center->number/10;
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[1]=a[R+1][C]->number/10;
        }

        if(a[R+2][C]->number>10)
        {
            ThreeNum[2]=a[R+2][C]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            a[R+i][C]->number=0;
            Destroy *d;
            switch(ThreeNum[i])
            {
            case 0:  // basis candy
                a[R+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+1+i][C]);
                delete d;
                break;
            }
        }
        break;

    case 7:
        num=num%10;


        if(a[R][C-1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R][C-1]->number/10;
        }
        ThreeNum[1]=a[R][C]->number/10; //center candy is chocolate
        if(a[R][C+1]->number>10)
        {
            ThreeNum[2]=a[R][C+1]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
    case 8:
        num=num%10;
        ThreeNum[0]=a[R][C]->number/10;
        if(a[R][C+1]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[1]=a[R][C+1]->number/10;
        }
        if(a[R][C+2]->number>10)
        {
            ThreeNum[2]=a[R][C+2]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
            {
            case 0:  // basis candy
                a[R][C+i]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R][C+i]);
                delete d;
                break;
            }
        }
        break;
    case 9:
        num=num%10;
        if(a[R][C-2]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R][C-2]->number/10;
        }
        if(a[R][C-1]->number>10)
        {
            ThreeNum[1]=a[R][C-1]->number/10;
        }
        ThreeNum[2]=a[R][C]->number/10;

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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

    case 10:
        num=num%10;


        if(a[R-1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R-1][C]->number/10;
        }

        ThreeNum[1]=a[R][C]->number/10;

        if(a[R+1][C]->number>10)
        {
            ThreeNum[2]=a[R+1][C]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
     break ;
    case 11:
        num=num%10;
        if(a[R-2][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[0]=a[R-2][C]->number/10;
        }

        if(a[R-1][C]->number>10)
        {
            ThreeNum[1]=a[R-1][C]->number/10;
        }
        ThreeNum[2]=a[R][C]->number/10;

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
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
    case 12:
        num=num%10;
        ThreeNum[0]=a[R][C]->number/10;
        if(a[R+1][C]->number>10)  // number/10=type of candy  1=horizontal, 2=vertical, 3=bomb
        {
            ThreeNum[1]=a[R+1][C]->number/10;
        }

        if(a[R+2][C]->number>10)
        {
            ThreeNum[2]=a[R+2][C]->number/10;
        }

        for (int i=0;i<3;i++)
        {
            Destroy *d;
            switch(ThreeNum[i])
            {
            case 0:  // basis candy
                a[R+i][C]->number=0;
                break;
            case 1:
                d = new Vertical;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 2:
                d = new Horizontal;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            case 3:
                d = new NineBlock;
                d->eliminate(a,a[R+i][C]);
                delete d;
                break;
            }
        }
        break;
    }

}

void Three::eliminate(Blank *a[10][10], Blank *center)
{
    int C=center->column;
    int R=center->row;
    center->number=0;
    int ThreeNum[3]={0};
    Destroy * d;
    if (condition(a,a[R][C])==10||condition(a,a[R][C])==4)
    {
       for(int i=R-1;i<R+2;i++)
       {
            if(a[i][C]->number>0)
            {
                ThreeNum[i]=a[i][C]->number/10; //type of colume
            }
       }
       for(int i=R-1;i<R+2;i++)
       {
           switch (ThreeNum[i]) {
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
    else if(condition(a,a[R][C])==5||condition(a,a[R][C])==11)
    {

        for(int i=R-2;i<R+1;i++)
        {
             if(a[i][C]->number>0)
             {
                 ThreeNum[i]=a[i][C]->number/10; //type of colume
             }
        }
        for(int i=R-2;i<R+1;i++)
        {
            switch (ThreeNum[i]) {
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
    else if(condition(a,a[R][C])==6||condition(a,a[R][C])==12)
    {

        for(int i=R;i<R+3;i++)
        {
             if(a[i][C]->number>0)
             {
                 ThreeNum[i]=a[i][C]->number/10; //type of colume
             }
        }
        for(int i=R;i<R+3;i++)
        {
            switch (ThreeNum[i]) {
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
    else if(condition(a,a[R][C])==1||condition(a,a[R][C])==7)
    {
        for(int i=C-1;i<C+2;i++)
        {
             if(a[R][i]->number>0)
             {
                 ThreeNum[i]=a[R][i]->number/10; //type of colume
             }
        }
        for(int i=C-1;i<C+2;i++)
        {
            switch (ThreeNum[i]) {
            case 0:
              a[R][i]->number=0;
              break;
            case 1:
              d= new Vertical;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 2:
              d=new Horizontal;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 3:
              d= new NineBlock;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
           }
        }
    }
    else if(condition(a,a[R][C])==2||condition(a,a[R][C])==8)
    {
        for(int i=C;i<C+3;i++)
        {
             if(a[R][i]->number>0)
             {
                 ThreeNum[i]=a[R][i]->number/10; //type of colume
             }
        }
        for(int i=C;i<C+3;i++)
        {
            switch (ThreeNum[i]) {
            case 0:
              a[R][i]->number=0;
              break;
            case 1:
              d= new Vertical;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 2:
              d=new Horizontal;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 3:
              d= new NineBlock;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
           }
        }
    }
    else if(condition(a,a[R][C])==3||condition(a,a[R][C])==9)
    {
        for(int i=C-2;i<C+1;i++)
        {
             if(a[R][i]->number>0)
             {
                 ThreeNum[i]=a[R][i]->number/10; //type of colume
             }
        }
        for(int i=C-2;i<C+1;i++)
        {
            switch (ThreeNum[i]) {
            case 0:
              a[R][i]->number=0;
              break;
            case 1:
              d= new Vertical;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 2:
              d=new Horizontal;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
            case 3:
              d= new NineBlock;
              d->eliminate(a,a[R][i]);
              delete d;
              break;
           }
        }
    }

}

