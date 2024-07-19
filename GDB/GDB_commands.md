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
