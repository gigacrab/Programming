entry = 0
bad = True
while(entry < 3):
    n = input("Enter a number: ")
    if n.isdigit() and n != "0":
        n = int(n)
    else:
        print("error found, enter positive integer number")
        entry += 1
        continue
    sum = 0
    for i in range(1, n+1):
        sum += i
    print("sum of the numbers series [1 to", str(n)+"] is:", sum)
    choice = input("Do you want to continue....[Y] - Yes or press any key to exit :")
    if choice.upper() == "Y":
        continue
    else:
        bad = False
        break
if bad:
    print("program terminating... you've exceeded the maximum data entry limits")
else:
    print("Thank you. see you soon...")