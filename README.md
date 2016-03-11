# computationalphysics_N2013301020035
##My previous experience with python
I haven't wrote many programs with python until now.But I have known it for more than one year.One important reason is that I do not have onerous calculation tasks in my classes.Even if there is some homework of calculation or plotting,I can always solve it with mathematica.Therefore it is unnecessary for me to write program.

The time I fist met python is the year when I was a sophomore,and then I was focusing on my display in my classical dynamics class.After referring to many books,I had much interest on chaos and prepared to show how a chaos pendulum works in my display.But a big problem was faced with me,that I had just learned a litte C and C++,plotting such a picture was difficult for me.

At that time,one of my teachers,Mr Zhou,proposed a book and at the same time,python for me,which is totally unknown for me.Installig python 2.7.6 in my linux visual box,I looked through the examples provided by the installation package.I was deeply impressed by the surprising simpleness of the procedure.A cool animation can be rrealised by several rows simple codes.Besides,the codes were easy-undestandable compared with C,especial the codes for plotting.Although I was totally unfamiliar with python,it took only half an hour to understand almost all codes in one example.

I didn't start a new procedure at once,I just corrected an old one.I tried to show the moving orbit for a simple pendulum.It's pleasantly surprising that the procedure can show the formation of the orbit only if you use suited date.Along the procession of program,I could see the appearance of chaos clearly.And then I did an exercise in the *Computational Physics* of Nicholas J.Giordano,which was a tri-star system and also presented chaos.

Here I push one of my procedure about the tri-system in my repository,https://github.com/YMTheory/computationalphysics_N2013301020035/blob/master/tri-stars.py
which is simple but satisfies my need that time.I just used gravitational force formula and considerd the modification in the center-of-mass frame,and then got this result.I also give one situation here for some initial condition.https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/678.PNG
In the origin(0,0)here is the sun,and two stars spin around it.With an exaggerate mass ratio and initial orbit radius,an obvious chaos appears along time.
Although the procession of python is a little slower compared with C,but the time saved in programming makes it worthy learning it!



##The Realization of Display of Characters
I have already updated my dispaly procedure version 1.0:https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/test1.py.This little thing can display any characters in any order as you wish.However,in version 1.0 I have just added 6 characters 'A,I,M,O,U,Y',I will complete it little by little.But I didn't realize it in a big matrix,I just splitted a character into 5 rows,and saved every one in this way in a dictionary,and finally put different characters together.

And now I am concentrating on my version 2.0 to display a flash.
