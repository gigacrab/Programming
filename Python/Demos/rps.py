import random
while(True):
    bot = random.randint(1, 3)
    # 1 - rock
    # 2 - paper
    # 3 - scissors
    choice = int(input(": "))
    print(f"{bot} this is the bots choice")
    result = choice - bot
    if result == 0:
        print("Draw")
    elif result == 1 or result == -2:
        print("you win")
    else:
        print("you lose")
