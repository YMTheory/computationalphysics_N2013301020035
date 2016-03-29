#include<stdio.h>
#include"iostream.h"
#include"TGraph.h"
#include"TPaveText.h"
#include"TMath.h"
#include<iomanip>

double population[1000];
double realvalue[1000];
double t[1000];
double dt;
double a;
double b;
//double endtime;

void initialization()
{
    cout<<"Initial population ->"<<endl;
    cin>>population[0];
    realvalue[0] = population[0];
    cout<<"time step ->"<<endl;
    cin>>dt;
    cout<<"const a ->"<<endl;
    cin>>a;
    cout<<"const b ->"<<endl;
    cin>>b;
  //  cout<<"endtime ->"<<endl;
 //   cin>>endtime;
    t[0] = 0.0;
    return;
}/*initialize the variables*/

void claculation()
{
    double tmp;
    int i = 0;
    while (i<1000)
    {

	tmp = population[i]+a*population[i]*dt-b*population[i]*dt*population[i];
	cout<<population[i]<<" "<<t[i]<<endl;
	i++;
    	population[i] = tmp;
	t[i] = dt*i;

    }
return;
}

void population(){
   
   initialization();	
   claculation();

   TCanvas *c1 = new TCanvas("population","population",1200,1000);
   TGraph *g1=new TGraph(100,t,population);
   g1->SetTitle("Population");
   g1->GetXaxis()->SetTitle("time/year ");
   g1->GetYaxis()->SetTitle("Population");
   g1->SetMarkerSize(0.05);
   g1->SetLineWidth(3);
   g1->Draw("APC");

      TPaveText *pt = new TPaveText(0.6,0.7,0.98,0.98,"brNDC");
   pt->SetFillColor(18);
   pt->SetTextAlign(12);
   pt->AddText("large initial number situation");
   pt->AddText("a=10  b=0.01");
   pt->Draw();


return;
}
