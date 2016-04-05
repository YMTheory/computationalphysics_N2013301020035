#Study of Chapter 2

##Abstract
In this chapter we ues Euler method futher to solve the projectile problem.By considering the air resistance and change of pressure along with altitude both in isothermal and adiabatic model,it is impossible to sovle the ODE with analytical method,and the only way is numerical method--here we apply Euler mhthod.

##Content
###Demand
Consider a ball or a cannon shell or anything else projected in two dimension.If we are given initial condition(position and velocity),we are supposed to know the exact infomation of it in theory.However,if air resistance are invovled in,it is difficult to obtain the analytical result.So we can only calculate the numerical solution and errors and compare different results.

###Theory
Under ideal projectile situation,we have ![](http://latex.codecogs.com/gif.latex?\frac{d^2x}{dt^2}=0) and ![](http://latex.codecogs.com/gif.latex?\frac{d^2y}{dt^2}=g).
