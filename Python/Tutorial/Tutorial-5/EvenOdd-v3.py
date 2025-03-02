def getNumber():
    n = int(input("Enter your number: "))
    Check(n)

def Check(n):
    if 1 <= n <= 1000:
        if n%2 == 0:
            print("even number")
        else:
            print("odd number")
    else:
        print("Invalid input, Try again!")

getNumber()

