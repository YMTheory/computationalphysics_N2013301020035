Study of Chapter Six

##Info
Author:YuMiao

Student No.:2013301020035

##Abstract
In this chapter we consider a kind of typical motion -- wave.Here we also develop a numerical method which is applicable to all types of waves,and we can solve not only ideal case but also the realistic cases with waves on a string.

##Content
###Introduction

The central equation of wave motion is      
![wavemotion](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20%5E2y%7D%7B%5Cpartial%20t%5E2%7D%3Dc%5E2%20%5Cfrac%7B%5Cpartial%20%5E2y%7D%7B%5Cpartial%20x%5E2%7D%20%286.1%29).which is referred to as the wave equation without friction.Wherever the wave moves,such as string,electromagnetic field or surface of a lake,this equation arise,where x is the transmission distance,t is the time and c is a parameter that turns out to be the speed with which a wave moes on the string.

According to the analysis of force on the string,we can understand the equaiton.Consider the motion of the segment of the string denoted by the heavy line,with Newton second law,we can write down:
?[NT2](http://latex.codecogs.com/gif.latex?%28%5Cmu%20%5CDelta%20x%29%5Cfrac%7Bd%5E2y_i%7D%7Bdt%5E2%7D%3DTsin%5Ctheta_%7Bi&plus;1%7D-Tsin%5Ctheta_%7Bi%7D%286.2%29)

Then use a finite difference approximation for the angles:
![approx](http://latex.codecogs.com/gif.latex?sin%5Ctheta_i%20%5Capprox%20%5Cfrac%7By_i-y_%7Bi-1%7D%7D%7B%5CDelta%20x%7D%286.3%29)

We obtain:
![result](http://latex.codecogs.com/gif.latex?%5Cfrac%7Bd%5E2y_i%7D%7Bdt%5E2%7D%20%5Capprox%20%28%5Cfrac%7BT%7D%7B%5Cmu%7D%29%5Cfrac%7By_%7Bi&plus;1%7D-2y_%7Bi%7D&plus;y_%7Bi-1%7D%7D%7B%28%5CDelta%20x%29%5E2%7D%5Capprox%28%5Cfrac%7BT%7D%7B%5Crho%7D%29%5Cfrac%7B%5Cpartial%20%5E2y%7D%7B%5Cpartial%20x%5E2%7D%286.4%29),which is precisely the form of (6.1).

Now our job is to develop a numerical scheme for solving.Here what we need to do is obtain time-dependent solutions opposite to what happened in solving Laplace equation.Still,we apply finite difference method.So we write down:
![discretize](http://latex.codecogs.com/gif.latex?%5Cfrac%7By%28i%2Cn&plus;1%29&plus;y%28i%2Cn-1%29-2y%28i%2Cn%29%7D%7B%28%5CDelta%20t%29%5E2%7D%5Capprox%20c%5E2%5Cfrac%7By%28i&plus;1%2Cn%29&plus;y%28i-1%2Cn%29-2y%28i%2Cn%29%7D%7B%28%5CDelta%20x%29%5E2%7D%286.5%29).

Rearranging (6.5) we can express y(i,n+1) in terms of y at previous time steps,with the result:
![rearrange](http://latex.codecogs.com/gif.latex?y%28i&plus;1%2Cn%29%3D2%5B1-r%5E2%5Dy%28i%2Cn%29-y%28i%2Cn-1%29&plus;r%5E2%5By%28i&plus;1%2Cn%29&plus;y%28i-1%2Cn%29%5D%286.6%29).

Here while we loop every one step,we can get the next one states fof each points on the string from the previous two steps.If we loop long enough with different steps,we can know how the wave moves on the string.

###Exercise
As the wave equation is linear,one of the most important features is that the sum of two different solutions is also one solution.Here I give an initial state which is two the sum of different gaussian packets and show how they revolve.Then we can see if they propagate without affecting each other.Here are the images I got:

![init](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterSix/wave1.png)

This is the initial state.

![revolve](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterSix/wave2.png)

Processing...

###Conclude
We can see the the two waves propagate without affecting each other -- the sum of two different solutions is also a solution.

