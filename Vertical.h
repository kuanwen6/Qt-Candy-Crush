#ifndef VERTICAL_H
#define VERTICAL_H
#include "Destroy.h"
#include "Nineblock.h"
#include "Horizontal.h"

class Vertical:public Destroy
{
public:
    Vertical();
    virtual ~Vertical();
    virtual int condition(Blank*a[10][10], Blank * center);
    virtual void spawn(Blank*a[10][10],Blank * center,int mode);
    virtual void eliminate(Blank*a[10][10], Blank * center);
};

#endif // VERTICAL_H
