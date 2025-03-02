weight = float(input("Enter weight in pounds: "))
height = float(input("Enter heigh in inches: "))

bmi = weight * 703 / height**2
print(bmi)
if 18.5 <= bmi <= 25:
    print("You are optimal")
elif bmi < 18.5:
    print("You are underweight")
elif bmi > 25: 
    print("You are overweight")
else:
    print("Invalid input, try again.")