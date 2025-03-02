#File name: mainModule.py


import calculate

def title():
    print('====================================')
    print('  Mini Math calculator for kids     ')
    print('====================================')
    Numbers()
 
def Numbers():
    number1,number2=int(input('Enter number 1: ')),int(input('Enter number 2: '))
    print(number1, ' + ' ,number2, '=', calculate.add(number1, number2))#complete the code
    print(number1, ' - ' ,number2, '=', calculate.minus(number1, number2))#complete the code
    print(number1, ' * ' ,number2, '=', calculate.product(number1, number2))#complete the code
    print(number1, ' / ' ,number2, '=', calculate.division(number1, number2))#complete the code
    
title()








