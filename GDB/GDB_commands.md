# GDB Commands Summary

## Starting Steps

- dont forget to create symbol table by using g++ file.cpp -o file.out -g
- gdb file.out
- start
- debug as you want

## basic commands

- start     s
- run       r
- refresh
- continue  c
- next      n
- step      s
- finish    fin
- quit      q

## Breakpoints

- break       b
- break Function Name
- break File Name:Line Number
- break Line Number
- break *Address
- break ... if Condition

- info breakpoints
- enable
- disable
- delete

## print

- print variable  
- p variable
- p &variable  ----address

- info locals

## watch

**Places a Hardware breakpoint on a variable**

- watch variable
- watch variable == value
- watch variable != value
- watch variable > value
- watch variable < value

## display

**Prints the value of a variable after each step**

- display variable
- display info -> gives the id of the displayed variables
- undisplay id

## Overwriting

- set variable = value
- If in a class, use set variable object.variable = value or Use Setter()

## Call

### Non-member functions
- call function_name(args)

### Member functions (Must not be implemented in the class`(inlined)`)

#### Non-Static

- call object.function_name(args)

#### Static

- call Class::function_name(args)

**To Get Prototype of The Function**

- ptype function_name
- whatis function_name

## Source

- list -> Shows the source code
- list Line Number
- list Function Name
- list File Name:Line Number
- list File Name:Function Name

**dissasembly**

- disassemble /s Function Name

**Remove Mangling**

- set print asm-demangle on
