ACCT_NO='123456789'
PASS_CODE='999***'
USER_NAME='Bill Gates'

#insert code here

def ProgramTitle():
    print('******************************')
    print('* WELCOME TO BANK of AMERICA *')
    print('******************************')
    print()

def menu():
    print('Availble Transactions: ')
    print('_______________________')
    print('  1. Withdrawal        ')
    print('  2. Deposit           ')
    print('  3. Exit              ')
    checkUser()

def checkUser():
    print('Enter your ',end='')
    AcctNo,PassCode=input('Account number: '),input('Passcode:')
    if AcctNo==ACCT_NO and PassCode==PASS_CODE:
        getOption()
    else:
        Err()
def Err():
    print('invalid input, Try again!')

def getOption():
    option=int(input('Enter your option: '))
    if option==1:
        #insert code here 
    elif option==2:
        #insert code here
    elif option==3:
        print('Thank you, See you again')
    else:
        Err()

ProgramTitle()
menu()

