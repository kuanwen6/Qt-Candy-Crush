#ifndef THREE_H
#define THREE_H

#include "Destroy.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Nineblock.h"
#include "Star.h"

class Three :public Destroy
{
public:
    Three();
    virtual ~Three();
    virtual int condition(Blank*a[10][10], Blank * center);
    virtual void spawn(Blank*a[10][10],Blank * center,int mode);
    virtual void eliminate(Blank*a[10][10], Blank * center);
};

#endif // THREE_H
