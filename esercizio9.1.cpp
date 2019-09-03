#include"montecarlo.h"
#include<cmath>
#include<iostream>
#include"random.h"
#include"vettore.h"
#include"vettoredati.h"
#include"funzionevBase.h"
#include"funzioneBase.h"
#include"chisfera.h"
#include<cstdlib>
#include"TMath.h"
#include"TApplication.h"
#include"TGraph.h"
#include"TAxis.h"
#include"TCanvas.h"

#define COST 20

using namespace std;

int main(int argc, char** argv) {

if(argc!=3){
	cout << "usage " << argv[0] << " Npunti ndim " << endl;
	return -1;
	}

int n_punti=atoi(argv[1]);
int dim=atoi(argv[2]);

vettore *inf=new vettoredati(dim);
vettore *sup=new vettoredati(dim);
chisfera *c=new chisfera(1);
montecarlo *m=new montecarlo();
vettoredati *v=new vettoredati(100);

double vcubo[COST];
double vsfera[COST];
double dimensione[COST];
double rapporto[COST];

//rapporto volume sfer/volume cubo (in generale, per dimensione <20)

for(int i=0; i< COST;i++){
dimensione[i]=(i+1);
dim=i+1;
vettore *inf=new vettoredati(dim);
vettore *sup=new vettoredati(dim);
for(int j=0;j<dim;j++){
	inf->setComponent(j, -1);
	sup->setComponent(j, 1);
}
vcubo[i]=pow(2, dim);
vsfera[i]=m->integral(c, inf, sup, n_punti);
rapporto[i]=(vsfera[i]/vcubo[i]);


}

TApplication *app=new TApplication("app", 0, 0);
TCanvas *tela=new TCanvas("c", "c");
TGraph *e=new TGraph(20, dimensione, rapporto);
e->SetTitle("Sn/Rn");
e->GetXaxis()->SetTitle("dimensione");
e->GetYaxis()->SetTitle("rapporto");
tela->cd();
e->Draw("A*");
tela->Print("graph.pdf");

dim=atoi(argv[2]);

//calcolo media e deviazione standard (usando la dimensione passata dall'utente)

for(int i=0;i<dim;i++){
	inf->setComponent(i, -1);
	sup->setComponent(i, 1);
}

cout << "calcolo media e deviazione standard per " << n_punti << " punti in dimensione " << dim << endl;

for(int i=0;i<100;i++){
	v->setComponent(i, m->integral(c, inf, sup, n_punti));
}

cout << "media = " << v->media() << endl;
cout << "deviazione standard = " << v->devstd() << endl;
cout << endl;

//confronto valore atteso valore misurato (per dimensione da 1 a 5)

cout << "confronto tra valore atteso e valore misurato" << endl;
for(int i=1;i<=5;i++){
dim=i;

cout << "dimensione " << dim << endl;

vettore *inf=new vettoredati(dim);
vettore *sup=new vettoredati(dim);

for(int j=0;j<dim;j++){
	inf->setComponent(j, -1);
	sup->setComponent(j, 1);
}


double vatteso=pow(M_PI, dim*0.5)/TMath::Gamma(dim*0.5+1);
cout << "volume atteso " << vatteso << endl;

cout << "volume calcolato " << m->integral(c, inf, sup, n_punti) << endl;

}


app->Run();


return 0;
}

