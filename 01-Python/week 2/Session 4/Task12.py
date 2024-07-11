import sys

def main():
    # Get the list of command-line arguments, excluding the script name
    arguments = sys.argv[1:]
    
    # Print the arguments
    if arguments:
        print("Command-line arguments:")
        for index, arg in enumerate(arguments):
            print(f"Argument {index + 1}: {arg}")
    else:
        print("No command-line arguments were provided.")

if __name__ == "__main__":
    main()
