#ValidatePassword.py

import login

pw = input("Enter your password: ")
while not login.validPassword(pw):
    print("That password isn't valid.")
    pw = input("Enter your password: ")
    login.validPassword(pw)
print("That is a valid password.")