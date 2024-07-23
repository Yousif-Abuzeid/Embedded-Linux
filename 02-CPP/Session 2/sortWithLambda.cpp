#include <iostream>
#include <algorithm> // For std::sort

void print_arr(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sorting in ascending order using a lambda function
    std::sort(arr, arr + size, [](int a, int b) {
        return a < b;
    });
    std::cout << "Sorted in ascending order: ";
    print_arr(arr, size);

    // Sorting in descending order using a lambda function
    std::sort(arr, arr + size, [](int a, int b) {
        return a > b;
    });
    std::cout << "Sorted in descending order: ";
    print_arr(arr, size);

    return 0;
}
