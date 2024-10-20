#include <iostream>

/**
 * @brief Template function to get the maximum of three values.
 * 
 * This function compares three values of any type that supports the '>' operator
 * and returns the maximum of the three.
 * 
 * @tparam T The type of the values to be compared.
 * @param val_1 The first value.
 * @param val_2 The second value.
 * @param val_3 The third value.
 * @return T The maximum of the three values.
 */
template <typename T>
T maxOfThree(T val_1, T val_2 ,T val_3){
    T max=val_1;
    if(val_2>max){
        max=val_2;
    }else if(val_3>max){
        max=val_3;
    }
    return max;
}

int main(){
    // Test with integers
    int a = 10, b = 20, c = 15;
    std::cout << "Max of " << a << ", " << b << ", and " << c << " is: " << maxOfThree<int>(a, b, c) << std::endl;

    // Test with floating-point numbers
    double x = 12.5, y = 20.5, z = 18.5;
    std::cout << "Max of " << x << ", " << y << ", and " << z << " is: " << maxOfThree<double>(x, y, z) << std::endl;

  

    return 0;
    
}