

try: 
    originalPrice = float(input("Enter the item's original price: "))
    discount = originalPrice * 0.2
except Exception as e:
    print(e)


