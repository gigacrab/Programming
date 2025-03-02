#CheckCase.py

def Case(word):
    out = 0
    if word.isupper():
        out = 1
    elif word.islower():
        out = 2
    return out