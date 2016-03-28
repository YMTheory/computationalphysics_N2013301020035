#Study of CHAPTER 1
##Abstract

In this chapter I solved simple radioactive decay problems with numerical method--Euler Method.However I achieved it by C++ under the root environment,for there is still somthing wrong with python in my visualbox.

##Contents
###Demands
1.The biggest challenge might be the installation of different python packages,such as numpy,matplotlib,especially the latter which also depends on other packages--libPNG and freetype.I met many problems through the installation.At last,I'm in an awkward situation that there is no error through my running of procedure,but no pictures came out.And I haven't found any information useful for this.

So I just quitted python for a while until I found useful solutions.To finish my homework,I installed ROOT in my visualbox to calculate and plot.

2.The demands of this chapter is solving radioactive-decay-like problems with Euler methods.I just finished the basic problem and picked Ex4 in the textbook.Here is What I have done.

###Introduction of ROOT
Root is a modular scirntific sofeware framwork.It provides all kinds of functionalities for big data processing,statistical analysis,visualisation and storage.I wrote my scripts in C++ while it also supports Python.

There are many useful packages and headfiles in ROOT.It's itself a powerful calculation tools,and some packages useful to me to analyze deviation and plot.After including the headfiles,what I need to do is to create a canva and plotted on it!

###Realization
1.Cutting off from Taylor Expansion is the core of Euler method.![](http://latex.codecogs.com/gif.latex?\N_U($Delta$t)=N_U(0)+\frac{dN_U}{dt}$Delta$t+\frac{1}{2}frac\{d^2N_U}{dt^2}($Deltat$)^2+...).If we cut off all the terms after the first order term,then ![](http://latex.codecogs.com/gif.latex?\N_Udt=N_U0+\frac{dN_U}{dt}),which means if we pick a dt small enough,we can replace the curve with straight line whose gradient is ![](http://latex.codecogs.com/gif.latex?\\frac{dN_U}{dt}).Therefore with Euler method,to solve an ODE,we just need the first-order gradient.

2.For a radioactive decay,we have that ![](http://latex.codecogs.com/gif.latex?\\frac{dN_U}{dt}=\frac{N_U}{tau}).According to the previous analysis,we obtain the result ![](http://latex.codecogs.com/gif.latex?\N_Udt=N_U0-\frac{N_U}{tau}*dt) with Euler method.Fortunately,this ODE is solveable,we can get the analytical method ![](http://latex.codecogs.com/gif.latex?\N_Ut=N_U0*Exp(\frac{t}{tau})).We can just compare these two results and plot them.

3.


