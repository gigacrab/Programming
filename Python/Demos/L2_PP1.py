#Lesson 2
#Programming Problem 1
#This program obtains item's original price and
#calculates its sale price, with a 20% discount

originalPrice = float(input('Enter the item\'s original price: '))

discount= originalPrice* 0.2
salePrice= originalPrice - discount

print('The sale price is', salePrice)

