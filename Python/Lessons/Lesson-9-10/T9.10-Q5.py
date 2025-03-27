data = (0,1,1,0,-1,-1,0,1,1,0,1,0,-1,-1,0,0,-1,1,1,0,0,1,-1,-1)
zeroCount = 0
oneCount = 0
negCount = 0

for i in data:
    if i == 0:
        zeroCount += 1
    elif i == 1:
        oneCount += 1
    else:
        negCount += 1

print("-"*30)
print("No. of zeros {:>14}".format(": " + str(zeroCount)))
print("No. of ones {:>15}".format(": " + str(oneCount)))
print("No. of negative numbers {:}".format(": " + str(negCount)))
print("-"*30)