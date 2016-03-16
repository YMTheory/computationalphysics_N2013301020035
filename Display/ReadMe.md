#The Realization of Display of Characters

##Abstract:
A method of dictionary and loop to dispaly characters on the screen is appied here.Just some basic python grammer is invovled.Processing the program,you can see the characters you entered displayed on th screen composed of "#","*"...

##Contents
###Demands
1.Display your name's pinyin on the screen by '#','*'...

2.Dispaly any characters you put in on the screen by '#','*'...

###Thinking
1.For every character we can save it into several rows.So we must list all 26 characters first,and then realise the display of them.

2.I can't use the order "print" to print different character(if so,they will be printed in different row,which is not what I need),so I must connect the same row of all characters first and use a "print" to print all rows on the screen.

3.I haven't understand how I can save a character into a matrix,so I decide to use the dictionary to realize it.

###Realization
1.I divide all 26 characters into 5 rows.At first,I save five dictionaries named"xxxxforall(Firstforall for the 1st row for example)",in each dictionary I save the first row for all 26 characters.

2.Then I save five empty dictionaries named "xxxxRow(FirstRow for the 1st row for example)" for the five rows needed to be printed.

3.After you enter several characters,I save them as a character string.By dividing them into the single and refer to the dictionary,I can obtain the corresponding value in the dictionary and save it in the empty dictionary.

4.What I still need to do is to connect all values in the same dictionary as a character string,then print it on the screen.

###Code
https://raw.githubusercontent.com/YMTheory/computationalphysics_N2013301020035/master/Display/test1.py

###Drawbacks
1.I haven't finished all 26 characters(For practicing,I just finished my name).

2.Starting a new line after the picture exceeds the weigth of the screen hasn't been realized.

3.Changing the position of characters on the screen is not possible for the present version.

###Glad to receive suggestion and correction.
