def charToASCII(ch):
    if len(ch)!=1:
        print("Please enter a single Character")
        return -1
    else :
        return ord(ch)

char = input("please enter a character :")

print(charToASCII(char))