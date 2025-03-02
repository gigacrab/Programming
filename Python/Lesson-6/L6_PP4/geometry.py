#File name : geometry.py

import circle
import rectangle

AREA_CIRCLE = 1
CIRCUMFERENCE_CIRCLE=2
AREA_RECTANGLE=3
PERIMETER_RECTANGLE=4
 
def main():
      display_menu()
      choice = int(input('Enter your choice: '))
      print('----------------------------------------------------')
      if choice==AREA_CIRCLE:
            radius = float(input("Enter the circle's radius: "))
            print("The area is", circle.area(radius))
      elif choice==CIRCUMFERENCE_CIRCLE:
            radius = float(input("Enter the circle's radius: "))
            print("The cirumferece is", circle.circumference(radius))     
      elif choice==AREA_RECTANGLE:
            width=float(input("Enter the rectangle's width:  ")) 
            length=float(input("Enter the rectangle's length:  "))
            print("The area is", rectangle.area(width,length))
      elif choice==PERIMETER_RECTANGLE:
            width=float(input("Enter the rectangle's width:  ")) 
            length=float(input("Enter the rectangle's length:  "))
            print("The perimeter is", rectangle.perimeter(width,length))
      else:
            print('Error! invalid selection')

def display_menu():
      print()
      print('\t Menu')
      print('1 : Area of a circle ')
      print('2 : Circumference of a circle')
      print('3 : Area of a rectangle')
      print('4 : Perimeter of a rectangle')
      
main()

                         
                        
                  
                         
                     
