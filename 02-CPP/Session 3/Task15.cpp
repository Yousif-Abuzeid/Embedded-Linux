#include <iostream>
#include <ostream>
#include <string.h>

namespace NotStd {

    /**
     * @class string
     * @brief A simple string class for demonstration.
     */
    class string {
    private:
        char * str;    ///< Pointer to the character array holding the string.
        int length;    ///< Length of the string.

    public:

        /**
         * @brief Constructs a new string object from a C-string.
         * @param inStr The C-string to initialize the string with.
         */
        string(const char* inStr): length(strlen(inStr)) {
            str = new char[length + 1];
            strcpy(str, inStr);
        }

        /**
         * @brief Default constructor.
         * Constructs an empty string object.
         */
        string(): length(0) {
            str = new char[1];
            str[0] = '\0';
        }

        /**
         * @brief Copy constructor.
         * @param other The other string object to copy from.
         */
        string(const string& other): length(other.length) {
            str = new char[length + 1];
            strcpy(str, other.str);
        }

        /**
         * @brief Overloaded stream insertion operator for printing the string.
         * @param os The output stream object.
         * @param str The string object to print.
         * @return The modified output stream object.
         */
        friend std::ostream& operator<<(std::ostream& os, const string& str);

        /**
         * @brief Copy assignment operator.
         * @param other The other string object to assign from.
         * @return The current string object.
         */
        string& operator=(const string& other) {
            if (this != &other) {
                delete[] str;
                length = other.length;
                str = new char[length + 1];
                strcpy(str, other.str);
            }
            return *this;
        }

        /**
         * @brief Assignment operator for C-strings.
         * @param inStr The C-string to assign from.
         * @return The current string object.
         */
        string& operator=(const char* inStr) {
            delete[] str;
            length = strlen(inStr);
            str = new char[length + 1];
            strcpy(str, inStr);
            return *this;
        }

        /**
         * @brief Concatenation assignment operator for string objects.
         * @param other The other string object to concatenate.
         * @return The current string object.
         */
        string& operator+=(const string& other) {
            char * temp = new char[length + other.length + 1];
            strcpy(temp, str);
            strcat(temp, other.str);
            delete[] str;
            str = temp;
            length += other.length;
            return *this;
        }

        /**
         * @brief Concatenation assignment operator for C-strings.
         * @param inStr The C-string to concatenate.
         * @return The current string object.
         */
        string& operator+=(const char* inStr) {
            char * temp = new char[length + strlen(inStr) + 1];
            strcpy(temp, str);
            strcat(temp, inStr);
            delete[] str;
            str = temp;
            length += strlen(inStr);
            return *this;
        }

        /**
         * @brief Concatenation operator for string objects.
         * @param other The other string object to concatenate.
         * @return A new string object containing the concatenated result.
         */
        string operator+(const string& other) {
            string temp = *this;
            temp += other;
            return temp;
        }

        /**
         * @brief Concatenation operator for C-strings.
         * @param inStr The C-string to concatenate.
         * @return A new string object containing the concatenated result.
         */
        string operator+(const char* inStr) {
            string temp = *this;
            temp += inStr;
            return temp;
        }

        /**
         * @brief Destructor.
         * Frees the allocated memory.
         */
        ~string() {
            delete[] str;
        }

        /**
         * @brief Equality operator for string objects.
         * @param other The other string object to compare with.
         * @return True if the strings are equal, false otherwise.
         */
        bool operator==(const string& other) {
            return strcmp(str, other.str) == 0;
        }

        /**
         * @brief Equality operator for C-strings.
         * @param inStr The C-string to compare with.
         * @return True if the strings are equal, false otherwise.
         */
        bool operator==(const char* inStr) {
            return strcmp(str, inStr) == 0;
        }

        /**
         * @brief Inequality operator for string objects.
         * @param other The other string object to compare with.
         * @return True if the strings are not equal, false otherwise.
         */
        bool operator!=(const string& other) {
            return strcmp(str, other.str) != 0;
        }

        /**
         * @brief Inequality operator for C-strings.
         * @param inStr The C-string to compare with.
         * @return True if the strings are not equal, false otherwise.
         */
        bool operator!=(const char* inStr) {
            return strcmp(str, inStr) != 0;
        }

        /**
         * @brief Less-than operator for string objects.
         * @param other The other string object to compare with.
         * @return True if the current string is less than the other, false otherwise.
         */
        bool operator<(const string& other) {
            return strcmp(str, other.str) < 0;
        }

        /**
         * @brief Less-than operator for C-strings.
         * @param inStr The C-string to compare with.
         * @return True if the current string is less than the C-string, false otherwise.
         */
        bool operator<(const char* inStr) {
            return strcmp(str, inStr) < 0;
        }
    };

    /**
     * @brief Overloaded stream insertion operator for printing the string.
     * @param os The output stream object.
     * @param str The string object to print.
     * @return The modified output stream object.
     */
    std::ostream& operator<<(std::ostream& os, const string& str) {
        os << str.str;
        return os;
    }

}

int main() {
    NotStd::string str1 = "Hello";
    NotStd::string str2 = " World";
    NotStd::string str3(str1);
    NotStd::string str4(" World");

    std::cout << str1 + str2 << std::endl;
    std::cout << str3 + str4 << std::endl;

    return 0;
}
