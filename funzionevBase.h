#ifndef __FUNZIONEVBASE_H__
#define __FUNZIONEVBASE_H__

#include"vettore.h"

class funzionevBase{
public:

virtual double eval(vettore *v) const=0;
};


#endif
