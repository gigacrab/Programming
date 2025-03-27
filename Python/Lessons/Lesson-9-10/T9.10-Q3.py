choice = "Y"
dict = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"]
result = ""
while choice == "Y":
    number = input("\nEnter a number from 1 to 10: ")
    if not number.isdigit():
        print("Error! Enter only numbers.")
        continue
    number = int(number)
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
        print("Roman letter for {} is {}".format(dict[number-1], result))
    else:
        print("Error! Number should be between 1 to 10 only.")
        continue
    choice = input("\nDo you want to continue?[Y] yes any other keys to exit: ").upper()
    print("-"*50)
print("Thank you see you again!")