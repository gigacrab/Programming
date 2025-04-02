def ask():
    print("-"*50)
    return input("Do you want to continue Y-Yes, other keys to Exit: ")

choice = "Y"
f = open("/home/littlecrabby/Programming/Python/Lessons/Lesson-11/studentRecord.txt", "w")
f = open("/home/littlecrabby/Programming/Python/Lessons/Lesson-11/studentRecord.txt", "a")
while(choice.upper() == "Y"):
    n = input("How many record(s) do you want to create?")
    if not n.isdigit() or int(n) < 1:
        print("Error! Enter a number more than 1.")
    else:
        for i in range(int(n)):
            scoreList = []
            name = input("Enter student #{} firstname and lastname: ".format(1+i))
            nameList = name.split()
            if not name.replace(" ", "").isalpha():
                print("Error! Enter firstname and lastname, record not saved.")
                break
            for a in range(3):
                score = int(input("Enter test marks for ENGFF0" + str(19 + a) + ": "))
                scoreList.append(score)
            if max(scoreList) > 100:
                print("Error! Check the range should be 0..100, record not saved.")
            else:
                f.write(str(nameList) + "\n")
                for score in scoreList:
                    f.write(str(score) + "\n")
                print("Data saved to studentRecord.txt")
    choice = ask()
    print("-"*50)
f.close()
print("Thank you, see you again.")