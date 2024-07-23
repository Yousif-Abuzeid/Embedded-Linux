#include <iostream>

void find_odd_even(int arr[], int arr_size, int even[], int &even_count, int odd[], int &odd_count) {
    even_count = 0;
    odd_count = 0;

    for (int i = 0; i < arr_size; ++i) {
        if (arr[i] % 2 == 0) {
            even[even_count++] = arr[i];
        } else {
            odd[odd_count++] = arr[i];
        }
    }
}

void print_arr(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int even[arr_size];
    int odd[arr_size];
    int even_count, odd_count;

    find_odd_even(arr, arr_size, even, even_count, odd, odd_count);

    std::cout << "Even numbers: ";
    print_arr(even, even_count);

    std::cout << "Odd numbers: ";
    print_arr(odd, odd_count);

    return 0;
}
