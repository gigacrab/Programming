#File name: mainModule.py

import checkName
import checkMark


def main():
    name1=input('Enter first name: ')
    name2=input('Enter last name: ')
    name=checkName.Check(name1,name2)
    marks=float(input('Enter Test mark  :'))
    letter=checkMark.Check(marks)
    if letter==None:
         print(name.title(),',unable to define your grade')
    else:
        print(name.title(),',your grade is:',letter)
     
main()
