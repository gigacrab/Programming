#Lesson 2
#Programming Problem 2

#Modify to answer L3-Programming problem 1

name = input("What is your name? ")
print(f"Hi! {name}")
studentID = input(f"What is your student ID? ")

test1=float(input("enter the first test score  :"))
test2=float(input("enter the second test score :"))
test3=float(input("enter the third test score  :"))
average=(test1+test2+test3)/3
print('Average: ',round(average))

if average >= 95:
    print(f"Congratulations {name}!")
else:
    pass