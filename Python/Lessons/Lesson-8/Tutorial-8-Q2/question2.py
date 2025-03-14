#question2.py

import analysis

while True:
    text = input("Enter a string without space: ")
    if text.isalnum():
        analysis.charCounter(text)
    else:
        print("Error, enter string without space. ")
    question = input("Do you want to continue.. Y for yes other keys for No: ")
    if question.upper() == "Y":
        continue
    else:
        print("See you again!")
        break