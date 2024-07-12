#include <iostream>

/**
 * @brief Checks if a given character is a vowel ('a', 'e', 'i', 'o', 'u' and their uppercase counterparts).
 *
 * This function determines if the input character is a vowel by comparing it against predefined vowel characters.
 * Both lowercase and uppercase versions of vowels are considered valid.
 *
 * @param ch The character to be checked.
 * @return true if the character is a vowel, false otherwise.
 *
 * @example
 * // Example usage:
 * char ch = 'A';
 * if (isVowel(ch)) {
 *     std::cout << ch << " is a vowel." << std::endl;
 * } else {
 *     std::cout << ch << " is not a vowel." << std::endl;
 * }
 */
bool isVowel(char ch) {
    switch (ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
    }
}

int main() {
    char ch;
    
    std::cout << "Enter a character: ";
    std::cin >> ch;
    
    if (isVowel(ch)) {
        std::cout << ch << " is a vowel." << std::endl;
    } else {
        std::cout << ch << " is not a vowel." << std::endl;
    }

    return 0;
}
