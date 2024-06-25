import os

def getConfiguration():
    DDR = []
    for i in range(8):
        mode = input(f"Please enter bit {i} Mode:")
        if mode == "in":
            DDR.append(0)
        else:
            DDR.append(1)
    return DDR

config = getConfiguration()
print(config)
f = open("init.c", "w")
f.write(f"void Init_Port_DIR(void) {{\n\
    DDRA = 0b{config[0]}{config[1]}{config[2]}{config[3]}{config[4]}{config[5]}{config[6]}{config[7]};\n\
}}\n")
f.close()