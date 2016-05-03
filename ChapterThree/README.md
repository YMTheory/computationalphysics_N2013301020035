#Study of Chapter Three

##Info
Author:YuMiao

Student No.:2013301020035

##Abstract
In this chapter,two more methods,Euler-Cromer method and Runge-Kutta method are introduced and applied into ODEs for oscillatory motion.Using different methods to solve the two first-order differentiate equations from the one second-order Newton equation,and we can compare the different results.

##Content
###Demands
1.Knowing the errors of simple Euler method to solve oscillatory motion.

2.Knowing the basic details of Euler-Cromer method and Runge-Kutta method.

3.Solving Newton equations with this two new methods and compare the results of different methods.

###Introduction
In previous chapters,we apply simple Euler method to solve ODEs and can get reasonable results.Now we consider oscillatory motion--one of themost common motion in physics,whose motion equation has the form of .But when we apply simple Euler method to solve this equation,we will get a weird result which diverges as follows:
![diversion](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/diversion.png)

We can see energy diverges with time increasing.This is not physically reasonable,but if we think Euler method carefully we can understand this result easily.In Euler method,we omit the second and higher order terms and calculate.So the error will always be positive and accumulate more and more.This will result in inherent unstability of numerical method.Here we consider the total energy of the pendulum--![energy](http://latex.codecogs.com/gif.latex?E%3D%5Cfrac%7B1%7D%7B2%7Dml%5E2%5Comega%20%5E2&plus;mgl%281-cos%5Ctheta%29) .In the limit of small thata the energy reduces into ![limit](http://latex.codecogs.com/gif.latex?E%3D%5Cfrac%7B1%7D%7B2%7Dml%5E2%28%5Comega%5E2&plus;%5Cfrac%7Bg%7D%7Bl%7D%5Ctheta%5E2%29).So we have ![difference](http://latex.codecogs.com/gif.latex?E_%7Bi&plus;1%7D%3DE_i&plus;%5Cfrac%7B1%7D%7B2%7Dmgl%28%5Comega_i%5E2&plus;%5Cfrac%7Bg%7D%7Bl%7D%5Ctheta_i%5E2%29%28%5CDelta%20t%29%5E2).For this reason,some more numerical methods are introduced for our problems.

Here we introduce two new methods--Euler-Cromer method and Runge-Kutta method,which are useful for oscillatory motion and planetary motion.

###Theory
1.Euler-Cromer Method:Nothing new actually compared with Euler method.It is typical for 2rd-order ODEs.In Euler method we calculate the position of one point with the velocity of last point,![Euler](http://latex.codecogs.com/gif.latex?%5Ctheta_%7Bi&plus;1%7D%3D%5Ctheta_i&plus;%5Comega_i%20%5CDelta%20t).Instead,in Euler-Cromer method,![Cromer](http://latex.codecogs.com/gif.latex?%5Ctheta_%7Bi&plus;1%7D%3D%5Ctheta_i&plus;%5Comega_%7Bi&plus;1%7D%20%5CDelta%20t)(First we must calculate the velocity of this point.).Although only a minor change,in oscillatory motion it makes energy converges.

2.Runge-Kutta Method:Choosing a suitable slope.The only difference between Euler method and Euler-Cromer method is che choice of slope.In Runge-Kutta method,neither the slope of the old point nor the slope of the new point is used,instead,we calculate a new slope which can make the error decreases to fourth order.![Runge-Kutta](http://latex.codecogs.com/gif.latex?x%28t&plus;%5CDelta%20t%29%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B6%7D%5Bf%28x_1%27%2Ct_1%27%29&plus;2f%28x_2%27%2Ct_2%27%29&plus;2f%28x_3%27%2Ct_3%27%29&plus;f%28x_4%27%2Ct_4%27%29%5D)
![RK](http://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20%26%5Ctext%20x_1%27%3Dx%28t%29%2Ct_1%27%3Dt%5C%5C%20%26%20%5Ctext%20x_2%27%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B2%7Df%28x_1%27%2Ct_1%27%29%5CDelta%20t%2Ct_2%27%3Dt&plus;%5Cfrac%7B1%7D%7B2%7D%5CDelta%20t%5C%5C%20%26%20%5Ctext%20x_3%27%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B2%7Df%28x_2%27%2Ct_2%27%29%5CDelta%20t%2Ct_3%27%3Dt&plus;%5Cfrac%7B1%7D%7B2%7D%5CDelta%20t%5C%5C%20%26%20%5Ctext%20x_4%27%3Dx%28t%29&plus;f%28x_3%27%2Ct_3%27%29%5CDelta%20t%2Ct_4%27%3Dt&plus;%5CDelta%20t%5C%5C%20%5Cend%7Bcases%7D).

3.What we should be concernd about is that Runge-Kutta is powerful for first-order equation while Euler-Cromer method is for second-order.And in our problem,to avoid diversion,we must choose Euler-Cromer method.But for each first-order equation,Euler method and Runge-Kutta method are both effective.

###Plots
First I list different results for the simplest problem:![harmonic](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2%5Ctheta%7D%7Bdt%5E2%7D%3D-%5Cfrac%7Bg%7D%7Bl%7D%5Ctheta) with g=9.8 and l=1.

![pendulum1](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/pendulum1.png)
We can see that the method for omega decides the results majorly.The results with the same method for omega are close to each other.I will list the difference among these results later.

Then I list different results for problem3.4 which seems as ![3.4](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2%5Ctheta%7D%7Bdt%5E2%7D%3D-%5Ctheta%5E3) for anharmonic oscillator.

![pendulum2](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/pendulum2.png)

Here the difference is samll in these first several periods.Also,I will list the difference data later.

###Comparison
Adding the square of difference on each point and calculate the average--for ![3.4](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2%5Ctheta%7D%7Bdt%5E2%7D%3D-%5Ctheta%5E3) we have:

Euler & Runge-kutta:0.00012258

Euler-RK & Runge-Kutta:0.00215825

RK-Euler & Euler:0.00130114

###Codes
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/pendulum.cpp

###Questions
In my programme,I keep meeting problems on the stability of numerical calculation.Is under any circumstances,Runge-Kutta method better than simple Euler method?The result of my programme is NOT!Maybe I made some mistake which I didn't realize in it.So I'm eager to receive any suggestion and help!


###Breaking Off
There is a breaking off in my homework for Wuhan University Outdoors Basketball Games -- "TengFei Bei" has began from April 20th.As a player in physics school team,I put almost all my concentration on the matches because it is the only big matches the whole year for us.So I have stopped refreshing my github for a week,but I will complete what I missed after a while.
![NBA](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/basketball.jpg)


###Chaos
Here I being to discuss something about chaos.A typical chaos system satisfys the Newton's law:![chaos](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2%5Ctheta%20%7D%7Bdt%5E2%7D%3D-%5Cfrac%7Bg%7D%7Bl%7Dsin%5Ctheta-q%5Cfrac%7Bd%5Ctheta%7D%7Bdt%7D&plus;F_Dsin%28%5COmega_Dt%29) .We can still use Euler-Cromer method to solve this second-order problem.But we can notice that as we change the amplitude of driving force,the system will change from a damped one to a period one,and furthermore,the period double and double,and suddenly,in some point,the system comes into chaos--we can not find any repetition.

The theta-time relation is plotted with different F_D.
![thetatime](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/thetatime.png)

And we can also draw Poincare section(phase space) of different F_D as follows:
![Poincare](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/omegatheta.png)
We can see that under non-chaos situation,the trajectory only appears some special space,while chaos,the points can totally fill all space.

And when I adjust the parameters F_D,I can find that chaos is a special condition which is not easy to achieve.Only in a small range,the system processs into chaos.

###Lorentz Model
Lorentz Model is a famous model in fluid mechanics,which is majorly applied into weather prediction.It is actually a simplication of Navier-Stokes equations,describing a fluid in a container whose top and bottom surfaces are held at different temperatures.Lorentz simplified this problem into three equations as follows:
![Lorentz](http://latex.codecogs.com/gif.latex?%5Cbegin%7Balign*%7D%20%26%5Cfrac%7Bdx%7D%7Bdt%7D%3D%20%5Csigma%20%28y-x%29%5C%5C%20%26%5Cfrac%7Bdy%7D%7Bdt%7D%3D-xz&plus;rx-y%20%5C%5C%20%26%5Cfrac%7Bdz%7D%7Bdt%7D%3Dxy-bz%20%5Cend%7Balign*%7D)

Here we can take parameter r the same as F_D in pendulum problem.If I draw the Poincare sections on 2-dimension plane,it is clearly that there are attractors(with reasonable r).Here I list all three 2D phase plane.

![xy](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/Lorentzyx.png)
![yz](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/Lorentzyz.png)
![zx](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/Lorentz.png)


Also,I make a small flash to show the z-time relation as r from 1 to 200.
![anim](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterThree/anim.gif)

###Conclusion
In Lorentz model,by scanning r from 1 to 200,we can see that chaos only appear some specail range.
