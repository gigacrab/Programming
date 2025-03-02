def getInput():
    i = input("Enter a character: ")
    checkChar(i)

def checkChar(i):
    if i.isalpha() and len(i) == 1:
        changedCh = changeCase(i)
        printCh(changedCh)
    else:
        if len(i) != 1:
            errMsg()
        else:
            print("Character must only be alphabets!")

def changeCase(i):
    out = i.swapcase()
    return out

def printCh(i):
    print(i.swapcase(), "-->", i)

def errMsg():
    print("Error, enter a single character!")

getInput()