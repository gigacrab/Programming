#Tutorial 2
#Question 1, Question 2
tutorial = input("Which tutorial would you like to run?(1/2/3/4/5): ")
if tutorial == "1":
    def coneVol(data):
        ans = []
        for i in data:
            volume = round(PI / 3 * i[0] * i[0] * i[1])
            ans.append(volume)
        return ans
    data = [[2.5, 6, 39], [1.8, 3.9, 13]]
    PI = 22/7
    while(True):
        try:
            choice = input("Would you like to enter your own values?(y/n) ")
            if choice.lower() == "y":
                try: 
                    radius = int(input("Radius: "))
                    height = int(input("Height: "))
                except Exception as e:
                    print(f"{e} Try again!")
                    continue
                print(f"Your cone's volume is {coneVol([[radius, height]])[0]}")
            elif choice.lower() == "n":
                volume = coneVol(data)
                print(f"Your volumes are {volume[0]} and {volume[1]}!")
            else: 
                print("Try again!")
                continue
            continu = input("Would you like to continue?(y/n) ")
            if continu.lower() == "y":
                continue
            elif continu.lower() == "n":
                break
        except: 
            print("Please try again.")
            continue    
elif tutorial == "2":
    name = input("Enter your name: ")
    year = int(input("Enter your year of birth YYYY: "))
    print(f"Hi {name} you're {2025 - year} years old!")
elif tutorial == "3":
    firstName = input("Enter your first name: ")
    lastName = input("Enter you last name: ")
    print(f"Hello {firstName}, {lastName}")
elif tutorial == "4":
    ProductCode = "ABC1190"
    ProductName = "Sony DVD Player"
    ProductPrice = 350.00
    print(ProductCode + " " + ProductName + " RM " + str(ProductPrice))
elif tutorial == "5":
    print("This program calculates the area of a circle")
    PI = 3.14159 #constant variable
    r = float(input("Enter radius: "))
    area = PI * r ** 2
    print("Area is", area)
else: 
    print("Selection not available.")
