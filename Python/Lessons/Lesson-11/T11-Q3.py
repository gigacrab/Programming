fileName = "/home/littlecrabby/Programming/Python/Lessons/Lesson-11/Tutorial_Q3.txt"
f = open(fileName, "r")

content = f.readlines()
modifiedContent = []

for i in content:
    if i == "0\n":
        i = "10\n"
    modifiedContent.append(i)

f = open(fileName, "w")
f = open(fileName, "a")

for i in modifiedContent:
    f.write(i)

f.close()