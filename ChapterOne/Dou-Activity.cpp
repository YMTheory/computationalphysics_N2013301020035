#include<stdio.h>
#include"iostream.h"
#include"TGraph.h"
#include"TPaveText.h"
#include<iomanip>

using namespace std;
int Dou_Activity(void)
{
    double NA_U[10000];
    double NB_U[10000];
    double t[10000];
    double dt = 0.05;
    int tau = 20;
    NA_U[0] = 100.;
    NB_U[0] = 10.;
    t[0] = 0.;
    double endtime = 70.;
    int i = 0;
    double tmpA = 0,tmpB = 0;
	while (t[i] < endtime && NA_U[i]>=0 && NB_U[i]>=0)
    {
	tmpA = NA_U[i] - NA_U[i]*dt/tau+NB_U[i]*dt/tau;
	tmpB = NB_U[i] + NA_U[i]*dt/tau-NB_U[i]*dt/tau;
        cout<<NA_U[i]<<" "<<NB_U[i]<<" "<<t[i]<<endl;
	i++;
	NA_U[i] = tmpA;
	NB_U[i] = tmpB;
	t[i] = dt*(i);
    }
   TCanvas *ym = new TCanvas("c1","Dou-Radiactivity",200,10,600,400);
   TGraph *g1=new TGraph(10000,t,NA_U);
   TGraph *g2=new TGraph(10000,t,NB_U);
//   for(int j=0;j<100000;j++) 
 // /{g1->SetPoint(j,time[j],N_U[j]);}
   

//   g2->SetLineWidth(1);
   g2->SetMarkerStyle(10);
   g2->SetMarkerColor(2);
   g2->SetMarkerSize(0.1);

   g1->SetMarkerColor(1);
   g1->SetMarkerSize(0.01);
   g1->SetTitle("Radiactivity");
   g1->SetMarkerStyle(8);
   g1->GetXaxis()->SetTitle("time/s ");
  // g1->GetXaxis()->SetRange(0,100);
   g1->GetYaxis()->SetTitle("N_U");  
   g1->GetYaxis()->SetRange(0,110);
  // g1->Draw("ap");
   g1->Draw("A*");
   g2->Draw("Psame");

   TLegend *legend = new TLegend(.75,.80,.95,.95);
   legend->AddEntry(g1,"A element");
   legend->AddEntry(g2,"B element");
   legend->Draw();

	
    return 0;
    










}
