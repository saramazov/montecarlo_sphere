#include"random.h"
#include<cmath>
#include<iostream>
#include "funzioneBase.h"
#include "gauss.h"


using namespace std; 

random::random(int seed) {

	m_seed=seed;
	m_a=1664525;
	m_c=1013904223;
	m_m=pow(2,31);
	

}
 
double random::rand() {

double d;
int n[2];
n[0]=m_seed;
n[1]=(m_a*n[0]+m_c)% m_m;
m_seed=n[1];
d=static_cast<double>(n[1])/static_cast<double>(m_m-1);


return d;

}

double random::gaussiana(double media,double sigma){

double a=media-5.0*sigma;
double b=media+5.0*sigma;

double x,y;
double appo=(sqrt(2*M_PI))*sigma;
 	
funzioneBase *f= new gauss(media,sigma);

	do {
		
		x=a+(b-a)*this->rand();;
		
		y=this->rand()/appo;
		
	}
	while (f->eval(x) < y); 

delete[] f;
return x;
}
double random::boxmuller(double media, double sigma) {

double s= this->rand();
double t=this->rand();

double R=sqrt(-2.*log(s));
double theta=2.*M_PI*t;

return media+sigma*R*cos(theta);
}


double random::exp(double rate) {

double x=this->rand();

return -rate*log(1.-x);
}

double random::uniform(double a, double b) {

double x=this->rand();
return a+(b-a)*x;
}
