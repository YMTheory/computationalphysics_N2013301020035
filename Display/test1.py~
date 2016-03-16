Firstforall  = {'A':'   #    ','Y':'#   # ','M':'  #   #   ','U':'#     # ','I':'  #####  ','O':' # # #  '}
Secondforall = {'A':'  # #   ','Y':' # #  ','M':' # # # #  ','U':'#     # ','I':'    #    ','O':'#     # '}
Thirdforall  = {'A':' #####  ','Y':'  #   ','M':'#   #   # ','U':'#     # ','I':'    #    ','O':'#     # '}
Fourthforall = {'A':'#     # ','Y':'  #   ','M':'#   #   # ','U':'#     # ','I':'    #    ','O':'#     # '}
Fifthforall  = {'A':'#     # ','Y':'  #   ','M':'#   #   # ','U':' # # #  ','I':'  #####  ','O':' # # #  '}


char = raw_input('Please put in the characters: ')
FirstRowKey  = {}
SecondRowKey = {}
ThirdRowKey  = {}
FourthRowKey = {}
FifthRowKey  = {}
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
	FirstRowKey[i]  = Firstforall[x]
	SecondRowKey[i] = Secondforall[x]
	ThirdRowKey[i]  = Thirdforall[x]
	FourthRowKey[i] = Fourthforall[x]
	FifthRowKey[i]  = Fifthforall[x]
#	print FirstRowKey

	First += FirstRowKey[i]
	Second += SecondRowKey[i]
	Third += ThirdRowKey[i]
	Fourth += FourthRowKey[i]
	Fifth += FifthRowKey[i]
#for i in range(0,len(char)):
#	First += FirstRowKey['i']

print First
print Second
print Third
print Fourth
print Fifth
