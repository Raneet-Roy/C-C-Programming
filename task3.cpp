#include <iostream>
#include <limits>

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30};
    const int size = sizeof(arr) / sizeof(arr[0]);

    int largest = std::numeric_limits<int>::min();
    int secondLargest = std::numeric_limits<int>::min();

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    std::cout << "The second-largest element in the array is: " << secondLargest << std::endl;
    return 0;
}
