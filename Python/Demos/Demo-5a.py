#Lesson 4
#File name:L4_Demo5a.py

# This sample program shows how to modify the if structure when
# the else part is removed

SALUTATION1='Ms'
SALUTATION2='Mr'
SALUTATION3='Madam'

name=input("Enter your name  : ")
gender=input("Enter [M]-Male or [F]-Female : ")

if (gender.upper()=='F' or gender.upper()=='M'):#to accept only M or F
     if (gender.upper()=='M'):
         print("Hello!", SALUTATION2, name.title())
     #else:
     if (gender.upper()=='F'):
          age = int(input("How young are you?"))
          if (age>=40):
               print("Hello!", SALUTATION3, name.title())
          else:
               print("Hello!", SALUTATION1, name.title())
else:
     print('Invalid: Program terminating..')       

