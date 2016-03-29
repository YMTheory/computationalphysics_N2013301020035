#Study of CHAPTER 1
##Abstract

In this chapter I solved simple radioactive decay problems with numerical method--Euler Method.However I achieved it by C++ under the root environment,for there is still somthing wrong with python in my visualbox.

##Contents
###Demands
1.The biggest challenge might be the installation of different python packages,such as numpy,matplotlib,especially the latter which also depends on other packages--libPNG and freetype.I met many problems through the installation.At last,I'm in an awkward situation that there is no error through my running of procedure,but no pictures came out.And I haven't found any information useful for this.

So I just quitted python for a while until I found useful solutions.To finish my homework,I installed ROOT in my visualbox to calculate and plot.

2.The demands of this chapter is solving radioactive-decay-like problems with Euler methods.I just finished the basic problem and picked Ex5 in the textbook.Here is What I have done.

3.Ex6 is connected with population problem,but there is nothing different.
###Introduction of ROOT
Root is a modular scirntific sofeware framwork.It provides all kinds of functionalities for big data processing,statistical analysis,visualisation and storage.I wrote my scripts in C++ while it also supports Python.

There are many useful packages and headfiles in ROOT.It's itself a powerful calculation tools,and some packages useful to me to analyze deviation and plot.After including the headfiles,what I need to do is to create a canva and plotted on it!

###Realization
1.Cutting off from Taylor Expansion is the core of Euler method.![](http://latex.codecogs.com/gif.latex?\N_U($Delta$t)=N_U(0)+\frac{dN_U}{dt}$Delta$t+\frac{1}{2}frac\{d^2N_U}{dt^2}($Deltat$)^2+...).If we cut off all the terms after the first order term,then ![](http://latex.codecogs.com/gif.latex?\N_Udt=N_U0+\frac{dN_U}{dt}),which means if we pick a dt small enough,we can replace the curve with straight line whose gradient is ![](http://latex.codecogs.com/gif.latex?\\frac{dN_U}{dt}).Therefore with Euler method,to solve an ODE,we just need the first-order gradient(still something wrong with my latex).

2.For a radioactive decay,we have that ![](http://latex.codecogs.com/gif.latex?\\frac{dN_U}{dt}=\frac{N_U}{tau}).According to the previous analysis,we obtain the result ![](http://latex.codecogs.com/gif.latex?\N_Udt=N_U0-\frac{N_U}{tau}*dt) with Euler method.Fortunately,this ODE is solveable,we can get the analytical method ![](http://latex.codecogs.com/gif.latex?\N_Ut=N_U0*Exp(\frac{t}{tau})).We can just compare these two results and plot them.

3.In my programme,I print three lines numbers which are the numerical results,analytical results and relative errors.And I plot two lines where the black one is the numerical result while the red one is the analytical result(the real one).Difference between the two is very small while dt=0.05.Also we can change the setting of dt,tau and other parameters to see the influence on the final results.

4.With the same methods,I finished Ex5 in my textbook,where two nucleus are involved and nothing else is different.The two N_U couple with each other but the only thing I need to know is the gradient.Of course,we can also compare the numerical result and analytical result.We can see it that after a while the two nuclei come to a balance point and the gradient equals zero.

5.I also finished Ex6 in the textbook.It's concerned with the problem of population--there are two parameters "a,b" compared of single-parameter decay problem.For different initial number,parameters must be given different values.Under differnet circumastances,the population may increase or decrease until come to an unchanged value.In this programme,I do not just write down what I need to do ,instead I define two functions "initializtion" and "calculation" and just use them in my main function,which makes the programme more readable.

###Plotting
Decay of one nucleus
![Radioactive decay](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Activity.png)
Decay of two nuclei
![Dou_Decay](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Dou_Activity.png)
Population
![Small init#](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Small%20Init.png)
![Large init#](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Large%20Init.png)

###Code
Codes for decay of one nucleus
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Activity.cpp
Codes for decay of two nuclei
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/Dou_Activity.png
Codes for population change
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterOne/population.cpp

###Drawback
1.I haven't plot errorbars in this version(they are so small that you can't see them even I plotted).`


###Glad to receive any questions and suggestion!
