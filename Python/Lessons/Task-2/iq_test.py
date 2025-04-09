def display_welcome():
    print("=== Welcome to the IQ Test Program ===")
    print("Answer the following questions. Type 'quit' at any time to exit.\n")

def ask_question(question, options, correct_option):
    print(question)
    options = options.split(",")
    for option in options:
        print(str(options.index(option) + 1) + "." + option)
    while True:
        answer = input("Your answer (1-4): ")
        if answer.lower() == 'quit':
            return 'quit'
        if answer.isdigit() and 1 <= int(answer) and int(answer) <= 4:
            if int(answer) == correct_option:
                correct = True
            else:
                correct = False
            return correct
        else:
            print("Invalid input. Please enter a number between 1 and 4.")

def run_test():
    questions = ["What comes next in the sequence: 2, 4, 8, 16, ?", "If all Bloops are Razzies, and all Razzies are Lazzies, are all Bloops definitely Lazzies?", "Which shape has the most sides?"]
    options = ["18,24,32,20", "Yes,No,Maybe,Not enough info", "Triangle,Pentagon,Hexogon,Octagon"]
    correct = [3, 1, 4]
    
    score = 0
    number_of_questions = len(questions)
    for i in range(number_of_questions):
        result = ask_question(questions[i], options[i], correct[i])
        if result == 'quit':
            return 'quit'
        elif result:
            print("Correct!\n")
            score += 1
        else:
            print("Wrong!\n")
    return score