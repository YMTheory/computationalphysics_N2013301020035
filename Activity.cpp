#include<stdio.h>
#include"iostream.h"
#include"TGraph.h"
#include"TPaveText.h"
#include<iomanip>

using namespace std;
int Activity(void)
{
    double N_U[100000];
    double t[100000];
    double dt = 0.01;
    int tau = 10;
    N_U[0] = 1000;
    t[0] = 0;
    int endtime = 50;
    int i = 0;
    double tmp = 0;
	while (t[i] < endtime && N_U[i]>0)
    {
	tmp = N_U[i] - N_U[i]*dt/tau;
	cout<<N_U[i]<<" "<<t[i]<<endl;
	i++;
	N_U[i] = tmp;
	t[i] = dt*(i);
    }
   TCanvas *ym = new TCanvas("Activity","Activity",1200,1000);
   TGraph *g1=new TGraph(100000,t,N_U);
  // for(int j=0;j<100000;j++) 
   //{g1->SetPoint(j,time[j],N_U[j]);}
   g1->SetMarkerSize(0.5);
   g1->SetTitle("Radiactivity");
   g1->SetMarkerStyle(8);
   g1->Draw("apl");
   g1->GetXaxis()->SetTitle("time/s ");
   g1->GetYaxis()->SetTitle("N_U");  
	
    return 0;
    










}
