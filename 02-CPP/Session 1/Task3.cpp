#include <iostream>


/**
 * @brief Prints a right-angle triangle using asterisks.
 *
 * This function prints a right-angle triangle where the number of rows
 * is specified by the input parameter. The triangle is formed using asterisks ('*'),
 * with the right angle located at the bottom-left corner.
 *
 * @param rows The number of rows for the right-angle triangle. It must be a non-negative integer.
 *
 * @example
 * // To print a right-angle triangle with 5 rows:
 * print_right_triangle(5);
 * 
 * Output:
 * *
 * **
 * ***
 * ****
 * *****
 */
void print_right_triangle(int rows){
    for(int i=0; i<=rows; i++){

        for ( int j=0 ; j < i; j++)
        {
            std::cout<<"*";
        }
        std::cout<<std::endl;
    }
}

int main() {

    print_right_triangle(5);
    return 0;
}