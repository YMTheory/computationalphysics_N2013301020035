Firstforall  = {'A':'   #    ','Y':'#   # ','M':'  #   #   ','U':'#     # ','I':'  #####  ','O':' # # #  '}
Secondforall = {'A':'  # #   ','Y':' # #  ','M':' # # # #  ','U':'#     # ','I':'    #    ','O':'#     # '}
Thirdforall  = {'A':' #####  ','Y':'  #   ','M':'#   #   # ','U':'#     # ','I':'    #    ','O':'#     # '}
Fourthforall = {'A':'#     # ','Y':'  #   ','M':'#   #   # ','U':'#     # ','I':'    #    ','O':'#     # '}
Fifthforall  = {'A':'#     # ','Y':'  #   ','M':'#   #   # ','U':' # # #  ','I':'  #####  ','O':' # # #  '}


char = raw_input('Please put in the characters: ')
FirstRow  = {}
SecondRow = {}
ThirdRow  = {}
FourthRow = {}
FifthRow  = {}
x = ''
First = ''
Second = ''
Third = ''
Fourth = ''
Fifth = ''
for i in range(0,len(char)):
#print char[i]
#	print Firstforall['Y']
#	print ord(char[i])
#	print chr(ord(char[i]))
	x = chr(ord(char[i]))
#	print x
	FirstRow[i]  = Firstforall[x]
	SecondRow[i] = Secondforall[x]
	ThirdRow[i]  = Thirdforall[x]
	FourthRow[i] = Fourthforall[x]
	FifthRow[i]  = Fifthforall[x]
#	print FirstRowKey

	First += FirstRow[i]
	Second += SecondRow[i]
	Third += ThirdRow[i]
	Fourth += FourthRow[i]
	Fifth += FifthRow[i]
#for i in range(0,len(char)):
#	First += FirstRowKey['i']

print First
print Second
print Third
print Fourth
print Fifth
