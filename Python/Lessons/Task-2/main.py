import iq_test

def main():
    iq_test.display_welcome()
    results = []

    while True:
        name = input("Enter your name (or type 'quit' to exit): ")
        if name.lower() == 'quit':
            break

        print("\nHi " + name + " let's begin the IQ Test!\n")
        score = iq_test.run_test()

        if score == 'quit':
            print("Test interrupted.\n")
            continue
        
        results.append(name + "," + str(score))
        print("\n" + name + " you scored " + str(score) + "/3.\n")

        cont = input("Do you want to add another user? (yes/no): ")
        if cont.lower() != 'yes':
            break

    print("\n=== All Results ===")
    for result in results:
        result = result.split(",")
        print(result[0] + ": " + result[1] + "/3")

    print("\nThank you for using the IQ Test Program!")

main()
