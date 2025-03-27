thisTuple = (0,0,1,1,1,1,0,1,1,0,1,1,0,1)
thisList = []
for i in thisTuple:
    if i == 0:
        thisList.append(-1)
    elif i == 1:
        thisList.append(-2)
print(thisList)