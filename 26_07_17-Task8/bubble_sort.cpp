#include <iostream>
#include <utility> // For std::swap
using namespace std;

// Optimized Bubble Sort
// Repeatedly steps through the list, compares adjacent elements, and swaps them if in wrong order
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to check if any swapping occurred in this pass

        // Last i elements are already in place (sorted end)
        for (int j = 0; j < n - i - 1; j++) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Early Exit Optimization: 
        // If no two elements were swapped in inner loop, array is already sorted
        if (!swapped) {
            break;
        }
    }
}

// Utility function to print array contents
void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    // Input dataset
    int data[] = {64, 25, 12, 22, 11, 90, 42};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);

    bubbleSort(data, size);

    cout << "Sorted array (Bubble Sort): ";
    printArray(data, size);

    return 0;
}