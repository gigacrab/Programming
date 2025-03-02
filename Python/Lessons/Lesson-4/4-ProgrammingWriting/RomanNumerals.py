number = int(input("Enter a number from 1 to 10: "))
result = ""
if 1 <= number <= 10:
    quotient = number // 5
    remainder = number % 5
    if remainder > 3:
        result = "I"*(5-remainder)
        if quotient < 1:
            result += "V"
        else:
            result += "X"
    else:
        if quotient == 1:
            result += "V"
        elif quotient == 2:
            result += "X"
        result += "I"*remainder   
    print(result)
else:
    print("Number not in range, try again.")