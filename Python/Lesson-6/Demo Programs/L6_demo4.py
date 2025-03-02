#File name: L6-demo4.py

def main():
    mark=input('enter your test marks:' )
    letter=Check(mark)
    print('your grade is:',letter)
    print()
    
def Check(mark):
    mark=float(mark) #changing string to float
    
    if mark>=0 and mark<=100:
        if  mark >= 89:
            letter='A*'
        elif mark>= 79:
            letter='A'
        elif mark >= 69:
            letter='B'
        elif mark>= 59:
            letter='C'
        elif mark>= 49:
            letter='D'
        elif mark>= 39:
            letter='E'
        else: 
            letter='F'
        return letter
    else:
        print('Error! marks should be [0..100]')

main()
