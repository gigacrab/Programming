#main.py

import checkAlpha
import checkCase
import checkNumber

word = input("Enter a single word: ")

if checkAlpha.Alpha(word) == 1:
    if checkCase.Case(word) == 1:
        print("Single word, has alphabets in uppercase")
    else:
        print("Single word, has alphabets in lowercase")
else:
    if checkNumber.Number(word) == 1:
        print("Word has number")
    else:
        print("It is not a single word")
