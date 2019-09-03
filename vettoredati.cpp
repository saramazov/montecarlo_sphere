#include"vettore.h"
#include"vettoredati.h"
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

vettoredati::vettoredati(unsigned int n):vettore(n) {}

vettoredati::vettoredati(unsigned int n,char* nomefile):vettore(n){
	
	ifstream stream;
	stream.open(nomefile);
	for (int i=0; i<m_n; i++) {stream>>m_v[i];}
	stream.close();
}

void vettoredati::print() {

	for (int i=0; i<m_n; i++) cout<<m_v[i]<<endl;
}

void vettoredati::print(char *nomefile) {

	ofstream stream;
	stream.open(nomefile);	
	for (int i=0; i<m_n; i++) {stream<<m_v[i]<<endl;}
	stream.close();
}


void vettoredati::scambia_by_reference(double &a, double &b) {

	double c=0;
	c=a;
	a=b;
	b=c;
}

void vettoredati::selection_sort()  {

	for (int i=0; i<m_n; i++) {
		for (int j=i+1; j<m_n; j++) {
			if (m_v[j]<m_v[i])
				scambia_by_reference(m_v[i], m_v[j]);
		}
	}
}
				
double vettoredati::media() {

	double m;
	for (int i=0; i<m_n; i++) {
		m+=m_v[i];
	}
return m/(static_cast<double>(m_n));
}

double vettoredati::devstd() {
	
	double d;
	double m=this->media();
	for (int i=0; i<m_n; i++) {
		d+=pow((m_v[i]-m),2);
	}
return sqrt(d/static_cast<double>(m_n));
}
