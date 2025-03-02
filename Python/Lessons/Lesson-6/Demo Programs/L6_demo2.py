#File name: L6_demo2.py
    

number = 10 #global variable

def main():
      global number #to modify the value in global variable
      number=15
      num=float(input('Enter a number :'))
      show_number(num)

def show_number(num):
      print("global value",format(number,'.2f'))
      print('Able to access global variable',number+num)
      

main()


 




 
