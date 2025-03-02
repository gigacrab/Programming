#File name : L6_demo3.py

CONTRIBUTION_RATE =0.05

def main():
      grossPay = float(input("Enter the gross pay:"))
      bonus=float(input("Enter the amount of bonus:"))
      show_pay(grossPay)
      show_bonus(bonus)

def show_pay(grossPay):
      contribution = grossPay * CONTRIBUTION_RATE
      print('Contribution for gross pay: $'\
            ,format(contribution, '.2f'),sep='')

def show_bonus(bonus):
      contribution= bonus * CONTRIBUTION_RATE
      print('Contribution for bonus: $'\
            ,format(contribution, '.2f'),sep='')

main()                        
                
