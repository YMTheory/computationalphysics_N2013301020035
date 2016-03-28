#include<stdio.h>
#include"iostream.h"
#include"TGraph.h"
#include"TPaveText.h"
#include"TMath.h"
#include<iomanip>

using namespace std;
int Activity(void)
{
    double dt,endtime;

    cout<<"Please print the value of dt"<<endl;
    cin>>dt;

    cout<<"Please print the value of endtime"<<endl;
    cin>>endtime;


    
    //const n = endtime/dt;
   // cout<<n<<endl;
    double N_U[10000];
    double t[10000];
    double real_N[10000];
    double ex[10000];
    double ey[10000];
    int tau;
   // N_U[0] =;
    t[0] = 0;
   // real_N[0] = 1000;
    ey[0] = 0;
    cout<<"Please print the value of tau"<<endl;
    cin>>tau;
    cout<<"Please print the value of N_U[0]"<<endl;
    cin>>N_U[0];
    real_N[0] = N_U[0];
    //cout<<"Please print the value of real_N"<<endl;
    int i = 0;
    double tmp = 0;
    for(int j=0;j<10000;j++){ex[j] = 0;}
    
    while(t[i]<endtime)
    {
	tmp = N_U[i] - N_U[i]*dt/tau;
	cout<<N_U[i]<<" "<<real_N[i]<<" "<<ey[i]<<endl;
	i++;
        cout<<tmp<<endl;
	N_U[i] = tmp;
	t[i] = dt*(i);
	real_N[i] = real_N[0]*exp(-t[i]/tau);
        ey[i] = real_N[i]-N_U[i];
    }


   TCanvas *ym = new TCanvas("Activity","Activity",1200,1000);
   TGraph *g1=new TGraph(10000,t,N_U);
   TGraph *g2=new TGraph(10000,t,real_N);
  // for(int j=0;j<100000;j++) 
   //{g1->SetPoint(j,time[j],N_U[j]);}
   g1->SetMarkerSize(0.3);
   //g2->SetMarkerSize(0.5);
   g1->SetTitle("Radiactivity");
   g1->GetXaxis()->SetTitle("time/s ");
  // g1->SetMarkerStyle(15);
   g1->GetYaxis()->SetTitle("N_U"); 
    
   g2->SetMarkerColor(2);
   g2->SetMarkerStyle(20);
   g2->SetMarkerSize(0.3);
   //g1->SetMarkerStyle(15);
   //g1->SetLineWidth(0.01);
  // g2->SetLineWidth(0.01);
   g1->Draw("A*");
   g2->Draw("Psame");
   
   TLegend *legend = new TLegend(.75,.80,.95,.95);
   legend->AddEntry(g1,"Numerical result");
   legend->AddEntry(g2,"Analytical result");
   legend->Draw();
  	
    return 0;
    










}
