#include"montecarlo.h"
#include<cmath>
#include<iostream>
#include"random.h"
#include"vettore.h"
#include"vettoredati.h"
#include"funzionevBase.h"
#include"funzioneBase.h"

using namespace std;

montecarlo::montecarlo(){

m_r=new random(1);
}

double montecarlo::integral(funzionevBase *f, vettore *inf, vettore *sup ,int n_punti){

vettore *v=new vettoredati(inf->getN());
double accu=0;
double volume=1.;
for(int i=0;i<n_punti;i++){
	for(int j=0;j<inf->getN();j++){
		v->setComponent(j, m_r->uniform(inf->getComponent(j), sup->getComponent(j)));	
		

	}
accu+=f->eval(v);

}
for(int i=0;i<inf->getN();i++)
	volume*= (sup->getComponent(i)-inf->getComponent(i)); //volume del cubo!

int q=m_r->uniform(1, 1500);
m_r->setSeed(q);

return volume*accu/(static_cast<double>(n_punti));
}

double montecarlo::integral(funzioneBase *f, double inf, double sup ,int npunti){

double v;
double accu=0;

for(int i=0;i<npunti;i++){
	v=m_r->uniform(inf, sup);	
	
accu+=f->eval(v);

}

int q=m_r->uniform(1, 1500);
m_r->setSeed(q);

return (sup-inf)*accu/(static_cast<double>(npunti));
}


