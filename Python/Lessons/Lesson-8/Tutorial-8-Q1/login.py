#login.py

def validPassword(pw):
    correctLength = False
    hasUppercase = False
    hasLowercase = False
    hasDigit = False

    if len(pw) >= 8:
        correctLength = True
    
    for c in pw:
        if c.isupper():
            hasUppercase = True
        elif c.islower():
            hasLowercase = True
        elif c.isdigit():
            hasDigit = True
    
    if correctLength and hasUppercase and hasLowercase and hasDigit:
        isValid = True
    else:
        isValid = False
    
    return isValid



