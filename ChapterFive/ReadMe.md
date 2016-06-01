Study of Chapter Five

##Info
Author:YuMiao

Student No.:2013301020035

##Abstract
In thie chapter,we get touch with a new calculation method -- relaxation method and some improvement of it.Here I use it to solve potential in some different circumstances and compare different results.

##Content
###Introduction
In regions of space that do not contain any electric charges,the electric potential obeys Laplace equation:
![Laplace Equation](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20%5E2%20V%7D%7B%5Cpartial%20x%5E2%7D&plus;%5Cfrac%7B%5Cpartial%20%5E2%20V%7D%7B%5Cpartial%20y%5E2%7D&plus;%5Cfrac%7B%5Cpartial%20%5E2%20V%7D%7B%5Cpartial%20z%5E2%7D%3D0%20%285.1%29)
And we also will be told the boundary conditions the potential must satisfy.That is to say,we should find V(x,y,z) which satisfy both Laplace Equation and the corresponding boundary conditions.To solve this PDE(partial differential equations),a
new method is introduced -- relaxation method.We write x as i*delta_x,the same with y,z.And then we do discretization as follows:
![Firstpartial](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20V%7D%7B%5Cpartial%20x%7D%3D%5Cfrac%7BV%28i&plus;1%2Cj%2Ck%29-V%28i%2Cj%2Ck%29%7D%7B%5CDelta%20x%7D%20%285.2%29).Similarly,we can write ![secondorder](http://latex.codecogs.com/gif.latex?%5Cfrac%7B%5Cpartial%20%5E2%20V%7D%7B%5Cpartial%20x%5E2%7D%5Capprox%5Cfrac%7B1%7D%7B%5CDelta%20x%7D%5Cleft%20%5B%20%5Cfrac%7B%5Cpartial%20V%7D%7B%5Cpartial%20x%7D%28i&plus;%5Cfrac%7B1%7D%7B2%7D%29-%20%5Cfrac%7B%5Cpartial%20V%7D%7B%5Cpartial%20x%7D%28i-%5Cfrac%7B1%7D%7B2%7D%29%20%5Cright%20%5D%285.3%29).Here we apply the request that ![request](http://latex.codecogs.com/gif.latex?%5CDelta%20x%3D%5CDelta%20y%3D%5CDelta%20z%285.4%29),we can simplify Laplace equation as follows:![simplify](http://latex.codecogs.com/gif.latex?V%28i%2Cj%2Ck%29%3D%5Cfrac%7B1%7D%7B6%7D%5Cleft%20%5B%20V%28i&plus;1%2Cj%2Ck%29&plus;V%28i-1%2Cj%2Ck%29&plus;V%28i%2Cj&plus;1%2Ck%29&plus;V%28i%2Cj-1%2Ck%29&plus;V%28i%2Cj%2Ck&plus;1%29&plus;V%28i%2Cj%2Ck-1%29%20%5Cright%20%5D%285.5%29).

Now we have discretize Laplace Equation and then here comes the numerical method for it.We should not start from at the boundary cause we need to know all its neighbor points to calculate the value of a point.So this approach requires us initial conditions--which we can give any values.Then we begin to calculate the values from any direction,and repeat this step until the error is reasonable.

The particular algorithm we have just described is known as the Jacobi method.It works as we calculate the new values totally with the old ones.So in our calculation we need keep two arrays to save new values and old values seperately.

To check if the results we get are accurate enough,we are suuposed to sum  difference between old values and new ones on all points up and compare it with N*e^-5 where N is the number of points in the system.

###Improvement
However there are some improvements to save our work time.For example,the Gauss-Seidel method,which uses the new values as they become avaible.The order in which they become avaible depends on how you loop through the grid.Here I list the relation:![GuassSediel](http://latex.codecogs.com/gif.latex?V_%7Bnew%7D%28i%2Cj%29%3D%5Cfrac%7B1%7D%7B4%7D%5Cleft%20%5B%20V_%7Bold%7D%28i&plus;1%2Cj%29&plus;V_%7Bnew%7D%28i-1%2Cj%29&plus;V_%7Bold%7D%28i%2Cj-1%29&plus;V_%7Bnew%7D%28i%2Cj-1%29%20%5Cright%20%5D%285.6%29).Thus we need only one array to finish our work.

Another method which fasten the process more is called simultaneous over-relaxation(SOR).Let V*(i,j) be the new value of the potential calculated using the Guass-Seidel method.We then write ![delat V](http://latex.codecogs.com/gif.latex?%5CDelta%20V%28i%2Cj%29%5Cequiv%20V%5E*%28i%2Cj%29-V_%7Bold%7D%28i%2Cj%29%285.7%29).To speed up convergence we will change the potential by a larger amount calculated according to ![SOR](http://latex.codecogs.com/gif.latex?V_%7Bnew%7D%28i%2Cj%29%3D%5Calpha%20%5CDelta%20V%28i%2Cj%29&plus;V_%7Bold%7D%28i%2Cj%29%285.8%29).The best choice of alpha is ![alpha](http://latex.codecogs.com/gif.latex?%5Calpha%20%5Capprox%20%5Cfrac%7B2%7D%7B1&plus;%5Cpi%20/L%7D%285.9%29).

###Images
Here I concentrate on a problem on the book -- two finite plates with potential +1V and -1V and boundary conditions defined by x=+1,x=-1,y=+1 and y=-1 with V=0.What we need to do is to calculate the potential in the area.Here I simply apply Jacobi algorithm and Guass-Seidel Method and compare the results.In the first condition,I seperate the grid into 8*8.

![Initial condition](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterFive/Initial.PNG)

This is the initial conditions I have set.

![Jacobi](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterFive/Jacobi.PNG)

This is the result with Jacobi algorithm.

![GS](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterFive/GS.PNG)

This is the result with Gauss-Seidel Method.

![SOR](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterFive/SOR.PNG)

We can see that we run 17 times to get a reasonable result with Jacobi algorithm and 28 times with Guass-Seidel method.

Then I change the grid into 16*16,and still use the three different method to calculate this problem.

###Result
Here I list the times to get a reasonable result with the three different method in the two conditions.

![Compare](https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/ChapterFive/compare.PNG)
