#Study of Chapter 2

##Abstract
In this chapter we ues Euler method futher to solve the projectile problem.By considering the air resistance and change of pressure along with altitude both in isothermal and adiabatic model,it is impossible to sovle the ODE with analytical method,and the only way is numerical method--here we apply Euler mhthod.

##Content
###Demand
Consider a ball or a cannon shell or anything else projected in two dimension.If we are given initial condition(position and velocity),we are supposed to know the exact infomation of it in theory.However,if air resistance are invovled in,it is difficult to obtain the analytical result.So we can only calculate the numerical solution and errors and compare different results.

###Theory
1.Under ideal projectile situation,we have

![ideal Newton equation](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2x%7D%7Bdt%5E2%7D%3D0%2C%5Cfrac%7Bd%5E2y%7D%7Bdt%5E2%7D%3D-g).

2.But in practice,we must put air resistance under consideration,thus the equation will become complicated.We write the drag force on our cannon shell as ![drag force](http://latex.codecogs.com/gif.latex?F_%7Bdrag%7D%3D-B_2v%5E2).And then the Newton second equations become 

![air resistance](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2x%7D%7Bdt%5E2%7D%3D-B_2vv_x%2C%5Cfrac%7Bd%5E2y%7D%7Bdt%5E2%7D%3D-B_2vv_y-g)

3.We futher consider the dependence of pressure p on altitude,and the problem become more complicated.In isothermal model,the relation is 

![isothermal](http://latex.codecogs.com/gif.latex?p%28y%29%3Dp%280%29e%5E%7B-mgy/k_BT%7D),
and in adiabatic model,the dependence is 

![adiabatic](http://latex.codecogs.com/gif.latex?p%28y%29%3Dp%280%29%281-%5Cfrac%7Bay%7D%7BT_0%7D%29%5E%7B%5Calpha%20%7D).And according to our model,we have

![drag force](http://latex.codecogs.com/gif.latex?F%5E*_%7Bdrag%7D%3D%5Cfrac%7Bp%7D%7Bp_0%7DF_%7Bdrag%7D%28y%3D0%29).

4.The purpose of us is to solve these complicated second order differential equations.

###Realization
1.By solving these 2nd-order equations under idela situation,we can write each of these second-order equations as two first-order differential equations.Therefore the problems become:
![four 1-order](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bdx%7D%7Bdt%7D%3Dv_x%2C%5Cfrac%7Bdv_x%7D%7Bdt%7D%3D0%2C%5Cfrac%7Bdy%7D%7Bdt%7D%3Dv_y%2C%5Cfrac%7Bdv_y%7D%7Bdt%7D%3D-g)
To use Euler method,we write each derivation in finite difference form as:

![finite](http://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20x_%7Bi&plus;1%7D%3Dx_i&plus;v_%7Bx%2Ci%7D%5CDelta%20t%5C%5C%20v_%7Bx%2Ci&plus;1%7D%3Dv_%7Bx%2Ci%7D%5C%5C%20y_%7Bi&plus;1%7D%3Dy_i&plus;v_%7By%2Ci%7D%5CDelta%20t%5C%5C%20v_%7By%2Ci&plus;1%7D%3Dv_%7By%2Ci%7D%20-g%5CDelta%20t%5C%5C%20%5Cend%7Bcases%7D).

And then we can apply Euler method as what we did in Chapter 1.

2.With the same method,we can solve the problems with air resistance even with changable pressure.What we need to do is write down the four finite equation and calculate the next condition repeatly.

###Plot
![plotting](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterTwo/projectile.png)

###Codes
In this homework,I try programming with "class".The most important thing is to write the class of the simplest projectile stuff--I write "init","Nextstep","Intersection" and "plot" functions.And then the only thing I need to do is to modify the "Nextstep" function to write the air resisitance classes.
Codes for projectile cannon shell:
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterTwo/projectile.cpp
