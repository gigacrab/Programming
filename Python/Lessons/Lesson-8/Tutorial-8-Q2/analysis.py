#analysis.py

def charCounter(text):
    upper = 0
    lower = 0
    digit = 0

    for c in text:
        if c.isupper():
            upper += 1
        elif c.islower():
            lower += 1
        elif c.isdigit():
            digit += 1
    
    print("___________________________________________")
    print("The number of uppercase letters:", upper)
    print("The number of lowercase letters", lower)
    print("The number of digits:", digit)
    print("Total number of characters:", len(text))
    print("___________________________________________")