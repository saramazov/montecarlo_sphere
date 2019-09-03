#ifndef __MONTECARLO_H__
#define __MONTECARLO_H__

#include"random.h"
#include"funzionevBase.h"
#include"funzioneBase.h"
#include"vettore.h"


class montecarlo{
public:
montecarlo();

double integral(funzionevBase *f, vettore *inf, vettore *sup ,int n_punti);
double integral(funzioneBase *f, double inf, double sup ,int npunti);
private:
random *m_r;


};


#endif
