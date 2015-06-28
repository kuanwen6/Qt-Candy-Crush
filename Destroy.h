#ifndef DESTROY_H
#define DESTROY_H

#include "blank.h"

class Destroy
{
public:
    Destroy();
    virtual ~Destroy();
    virtual int condition(Blank*a[10][10], Blank * center)=0;
    virtual void spawn(Blank*a[10][10],Blank * center,int mode)=0;
    virtual void eliminate(Blank*a[10][10], Blank * center)=0;
};

#endif // DESTROY_H
