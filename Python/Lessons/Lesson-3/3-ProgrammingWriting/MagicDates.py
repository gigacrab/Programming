print("Enter [mm/dd/yy]")
month = int(input("month: "))
day = int(input("day: "))
year = int(input("year [yy]: "))
if month * day == year:
    print(f"{month}/{day}/{year} is a magic date")
else:
    print("Date is not magic")