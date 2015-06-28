#ifndef NINEBLOCK_H
#define NINEBLOCK_H
#include "Destroy.h"
#include "Vertical.h"
#include "Horizontal.h"


class NineBlock :public Destroy
{
public:
    NineBlock();
    virtual ~NineBlock();
    virtual int condition(Blank*a[10][10], Blank * center);
    virtual void spawn(Blank*a[10][10],Blank * center,int mode);
    virtual void eliminate(Blank*a[10][10], Blank * center);
};

#endif // NINEBLOCK_H
