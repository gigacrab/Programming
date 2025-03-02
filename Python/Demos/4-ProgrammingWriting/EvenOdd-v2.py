number = int(input("Enter your number: "))
if 1 <= number <= 1000:
    if number%2 == 0:
        print("even number")
    else:
        print("odd number")
else:
    print("Invalid input, Try again!")


