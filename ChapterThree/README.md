###Study of Chapter Three

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
![diversion](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterTwo/diversion.png)

We can see energy diverges with time increasing.This is not physically reasonable,but if we think Euler method carefully we can understand this result easily.In Euler method,we omit the second and higher order terms and calculate.So the error will always be positive and accumulate more and more.This will result in inherent unstability of numerical method.Here we consider the total energy of the pendulum--![energy](http://latex.codecogs.com/gif.latex?E%3D%5Cfrac%7B1%7D%7B2%7Dml%5E2%5Comega%20%5E2&plus;mgl%281-cos%5Ctheta%29) .In the limit of small thata the energy reduces into ![limit](http://latex.codecogs.com/gif.latex?E%3D%5Cfrac%7B1%7D%7B2%7Dml%5E2%28%5Comega%5E2&plus;%5Cfrac%7Bg%7D%7Bl%7D%5Ctheta%5E2%29).So we have ![difference](http://latex.codecogs.com/gif.latex?E_%7Bi&plus;1%7D%3DE_i&plus;%5Cfrac%7B1%7D%7B2%7Dmgl%28%5Comega_i%5E2&plus;%5Cfrac%7Bg%7D%7Bl%7D%5Ctheta_i%5E2%29%28%5CDelta%20t%29%5E2).For this reason,some more numerical methods are introduced for our problems.

Here we introduce two new methods--Euler-Cromer method and Runge-Kutta method,which are useful for oscillatory motion and planetary motion.

###Theory
1.Euler-Cromer Method:Nothing new actually compared with Euler method.It is typical for 2rd-order ODEs.In Euler method we calculate the position of one point with the velocity of last point,![Euler](http://latex.codecogs.com/gif.latex?%5Ctheta_%7Bi&plus;1%7D%3D%5Ctheta_i&plus;%5Comega_i%20%5CDelta%20t).Instead,in Euler-Cromer method,![Cromer](http://latex.codecogs.com/gif.latex?%5Ctheta_%7Bi&plus;1%7D%3D%5Ctheta_i&plus;%5Comega_%7Bi&plus;1%7D%20%5CDelta%20t)(First we must calculate the velocity of this point.).Although only a minor change,in oscillatory motion it makes energy converges.

2.Runge-Kutta Method:Choosing a suitable slope.The only difference between Euler method and Euler-Cromer method is che choice of slope.In Runge-Kutta method,neither the slope of the old point nor the slope of the new point is used,instead,we calculate a new slope which can make the error decreases to fourth order.![Runge-Kutta](http://latex.codecogs.com/gif.latex?x%28t&plus;%5CDelta%20t%29%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B6%7D%5Bf%28x_1%27%2Ct_1%27%29&plus;2f%28x_2%27%2Ct_2%27%29&plus;2f%28x_3%27%2Ct_3%27%29&plus;f%28x_4%27%2Ct_4%27%29%5D)
![RK](http://latex.codecogs.com/gif.latex?%5Cbegin%7Bcases%7D%20%26%5Ctext%20x_1%27%3Dx%28t%29%2Ct_1%27%3Dt%5C%5C%20%26%20%5Ctext%20x_2%27%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B2%7Df%28x_1%27%2Ct_1%27%29%5CDelta%20t%2Ct_2%27%3Dt&plus;%5Cfrac%7B1%7D%7B2%7D%5CDelta%20t%5C%5C%20%26%20%5Ctext%20x_3%27%3Dx%28t%29&plus;%5Cfrac%7B1%7D%7B2%7Df%28x_2%27%2Ct_2%27%29%5CDelta%20t%2Ct_3%27%3Dt&plus;%5Cfrac%7B1%7D%7B2%7D%5CDelta%20t%5C%5C%20%26%20%5Ctext%20x_4%27%3Dx%28t%29&plus;f%28x_3%27%2Ct_3%27%29%5CDelta%20t%2Ct_4%27%3Dt&plus;%5CDelta%20t%5C%5C%20%5Cend%7Bcases%7D).

###Plots

