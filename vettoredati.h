#ifndef __vettoredati_h__
#define __vettoredati_h__
#include "vettore.h"

class vettoredati:public vettore {

public:

vettoredati (unsigned int n);             
vettoredati(unsigned int n, char* nomefile);
virtual void print();
virtual void print(char* nomefile);
virtual void selection_sort();
void scambia_by_reference(double &a, double &b);
double media();
double devstd();

};
#endif //__vettoredati_h__
