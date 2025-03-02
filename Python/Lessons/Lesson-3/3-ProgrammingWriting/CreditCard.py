annualSalary = int(input("Enter your annual salary, RM:"))
yearsEmployed = int(input("Enter the number of years employed:"))

if annualSalary >= 5000 and yearsEmployed:
    print("You qualify for credit card application")
else: 
    print("Sorry, you do not qualify for credit card application")