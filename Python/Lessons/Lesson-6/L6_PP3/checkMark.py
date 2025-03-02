#File Name: checkMark.py

def Check(marks):
    if marks>=0 and marks<=100:
        if  marks >= 89:
            letter='A*'
        elif marks>= 79:
            letter='A'
        elif marks >= 69:
            letter='B'
        elif marks>= 59:
            letter='C'
        elif marks>= 49:
            letter='D'
        elif marks>= 39:
            letter='E'
        else: 
            letter='F'
        return letter
    else:
        print('Error! marks should be [0..100]')
             
 
 
