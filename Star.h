#ifndef STAR_H
#define STAR_H

#include "Destroy.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Nineblock.h"

class Star:public Destroy
{
public:
    Star();
    virtual ~Star();
    virtual int condition(Blank*a[10][10], Blank * center);
    virtual void spawn(Blank*a[10][10],Blank * center,int mode);
    virtual void eliminate(Blank*a[10][10], Blank * center);
};

#endif // STAR_H
