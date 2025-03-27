record1 = ('John Smith','Savings', '12345678900')
newAcc = input("Enter a new account number: ")
record1 = list(record1)
record1[2] = newAcc
record1 = tuple(record1)

print(record1)