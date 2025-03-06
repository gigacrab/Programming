#File name: mainModule.py


import calculate

def title():
    print('====================================')
    print('  Mini Math calculator for kids     ')
    print('====================================')
    while(True):
        Numbers()
        choice = input("Do you want to continue? Y-Yes, other keys to Exit: ")
        if choice.upper() == "Y":
            continue
        else:
            print("Thank you, See you soon. Stay Safe")
            break
    
 
def Numbers():
    number1,number2=int(input('Enter number 1: ')),int(input('Enter number 2: '))
    print(number1, ' + ' ,number2, '=', calculate.add(number1, number2))#complete the code
    print(number1, ' - ' ,number2, '=', calculate.minus(number1, number2))#complete the code
    print(number1, ' * ' ,number2, '=', calculate.product(number1, number2))#complete the code
    print(number1, ' / ' ,number2, '=', calculate.division(number1, number2), "\n")#complete the code
    
title() 








