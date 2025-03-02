'''def PrintName():
    name = input("Enter Name: ")
    print(f"Hi, {name.title()}!")

PrintName()'''

def main():
    firstName = input("Enter your first name: ")
    lastName = input("Enter your last name: ")
    reverse(firstName, lastName)

def reverse(n1, n2):
    print(f"Your names reversed:- {n2} {n1}")

main()