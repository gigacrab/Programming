#main.py

import check
import Find

def maximum():
    num1=input('enter number 1: ')
    num2=input('enter number 2 : ')
    flag=check.checking(num1,num2)
    if flag==1: 
        print('The big number is: ',Find.findGreater(num1,num2))
    else:
        print('error.. enter numbers only')

maximum()