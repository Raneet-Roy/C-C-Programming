#include <iostream>
#include <vector>

using namespace std;

// partition function to select a pivot and divide the vector into two halves
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // select last element as pivot
    int i = low - 1; // index of smaller element
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// recursive quick sort function
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    int n = arr.size();
    quickSort(arr, 0, n-1);
    cout << "Sorted array: ";
    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
