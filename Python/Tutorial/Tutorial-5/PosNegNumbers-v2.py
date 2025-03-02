def main():
    n = getNumber()
    CheckNum(n)

def getNumber():
    n = int(input("Enter a Number: "))
    return n

def CheckNum(n):
    if n > 0:
        print("It's a positive number!")
    elif n < 0:
        print("It's a negative number!")
    else:
        print(n, "is neither positive nor negative!")

main()