annualSalary = int(input("Enter your annual salary, RM:"))
yearsEmployed = int(input("Enter the number of years employed:"))

message = ""

if annualSalary >= 5000 and yearsEmployed >= 2:
    print("You qualify for credit card application")
else: 
    print("Sorry, you do not qualify for credit card application")
    if annualSalary < 5000:
        print(f"Your salary RM{annualSalary} is less than RM5000")
    if yearsEmployed < 2:
        print(f"You have been employed for {yearsEmployed} year(s) should be more than 2 years")