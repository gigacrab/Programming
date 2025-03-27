bookList = []

while True:
    bookTitle = input("Enter the book title: ")
    bookList.append(bookTitle)
    choice = input("Do you want to add another item? ").upper()
    if choice == "Y":
        continue
    else:
        break

print("-"*20)
print("{:^20}".format("Book Title"))
print("-"*20)
for title in bookList:
    print(title)
print("-"*20)
print("Total number of books: {}".format(len(bookList)))