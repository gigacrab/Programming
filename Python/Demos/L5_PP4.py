#Lesson 5 - Programming Problem 4

def getInput():
    string=input('enter a single character: ')
    found=checkStr(string)
    #print(found)
    display(found) 

def checkStr(string):
    if len(string)==1:
        if string.isalpha() and string.isupper():
            return 1
        elif string.isalpha() and string.islower():
            return 2
        elif string.isdigit():
            return 3
        else:
            return 4
    else:
        err()
 
def display(found):
    if found==1:
        print('input is a single letter and in uppercase')
    elif found==2:
        print('input is a single letter and in lowercase')
    elif found==3:
        print('input is a single digit')
    else:
       unknownErr()

def err():
    print('Error, invalid input')

def unknownErr():
    print('unable to analyse the input')
    
getInput()