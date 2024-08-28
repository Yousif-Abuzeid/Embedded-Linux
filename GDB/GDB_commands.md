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


