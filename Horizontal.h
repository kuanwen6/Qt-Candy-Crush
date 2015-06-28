#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include"Destroy.h"
#include "Nineblock.h"
#include "Vertical.h"

class Horizontal :public Destroy
{
public:
    Horizontal();
    virtual ~Horizontal();
    virtual int condition(Blank*a[10][10], Blank * center);
    virtual void spawn(Blank*a[10][10],Blank * center,int mode);
    virtual void eliminate(Blank*a[10][10], Blank * center);
};

#endif // HORIZONTAL_H
