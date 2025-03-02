def readRecData():
    print("Enter the length and width of the first rectangle")
    length1 = float(input("Length: "))
    width1 = float(input("Width: "))

    print("Enter the length and width of the second rectangle")
    length2 = float(input("Length: "))
    width2 = float(input("Width: "))
    
    area1, area2 = calculateArea(length1, width1, length2, width2)

    compareArea(area1, area2)

def calculateArea(length1, width1, length2, width2):
    area1 = length1*width1
    area2 = length2*width2
    return area1, area2

def compareArea(area1, area2):
    if area1 > area2:
        print(f"{format(area1, '.2f')} of the first rectangle is greater than the second rectangle")
    elif area1 < area2:
        print(f"{format(area2, '.2f')} of the second rectangle is greater than the first rectangle")
    else: 
        print(f"The areas are the same")

readRecData()