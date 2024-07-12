#include <iostream>
#include <iomanip> // For std::setw

/**
 * @brief Prints multiplication tables up to a specified number.
 *
 * This function prints multiplication tables for numbers from 1 up to the given 'num'.
 * Each table is labeled and formatted neatly with results aligned using setw from <iomanip>.
 * Tables are separated by a line of dashes for clarity.
 *
 * @param num The maximum number for which multiplication tables will be printed.
 *
 * @example
 * // Example usage:
 * print_multiplication_table(5);
 *
 * Output:
 * Table for 1
 * -------------------------------------
 *  1 x  1 =  1
 *
 * Table for 2
 * -------------------------------------
 *  1 x  2 =  2     2 x  2 =  4
 *
 * Table for 3
 * -------------------------------------
 *  1 x  3 =  3     2 x  3 =  6     3 x  3 =  9
 *
 * Table for 4
 * -------------------------------------
 *  1 x  4 =  4     2 x  4 =  8     3 x  4 = 12     4 x  4 = 16
 *
 * Table for 5
 * -------------------------------------
 *  1 x  5 =  5     2 x  5 = 10     3 x  5 = 15     4 x  5 = 20     5 x  5 = 25
 */
void print_multiplication_table(int num) {
    for (int first_num = 1; first_num <= num; first_num++) {
        std::cout << "Table for " << first_num << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        
        for (int second_num = 1; second_num <= first_num; second_num++) {
            // Calculate and format the multiplication result
            int result = first_num * second_num;
            std::cout << std::setw(2) << second_num << " x " << std::setw(2) << first_num << " = " << std::setw(2) << result << "\t";
        }
        
        std::cout << std::endl << std::endl; // New line after each table
    }
}

int main() {
    print_multiplication_table(9);
    return 0;
}
