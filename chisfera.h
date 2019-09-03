#ifndef __CHISFERA_H__
#define __CHISFERA_H__

#include"funzionevBase.h"
#include"vettore.h"

class chisfera:public funzionevBase{

public:
chisfera(double r) {m_r=r;}
virtual double eval(vettore *v) const {if(v->modulo()<=m_r) return 1;
						else return 0;}
double get_r() const{return m_r;}

private:
double m_r;

};



#endif
