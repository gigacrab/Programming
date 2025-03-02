#File name: L6_demo1.py


number = 10 #global variable

def main():
      num=float(input('Enter a number :'))
      show_number(num)

def show_number(num):
      print("global value",format(number,'.2f'))
      print('Able to access global variable',number+num)
      

main()


