print("Enter the length and width of the first rectangle \
    \n--------------------------------------------------")
length1 = float(input("Length: "))
width1 = float(input("Width: "))

print("Enter the length and width of the second rectangle \
    \n --------------------------------------------------")
length2 = float(input("Length: "))
width2 = float(input("Width: "))

if length1 * width1 == length2 * width2:
    print("The areas are the same")
else: 
    print("The areas are not the same")