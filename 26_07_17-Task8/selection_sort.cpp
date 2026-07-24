#include <iostream>
#include <utility> // For std::swap
using namespace std;

// Selection Sort
// Repeatedly finds the minimum element from the unsorted portion and moves it to the front
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume current index is the minimum

        // Find the index of the smallest element in the remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update index of the new minimum
            }
        }

        // Swap the found minimum element with the first unsorted element
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
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
    int data[] = {83, 24, 51, 11, 95, 38, 67};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);

    selectionSort(data, size);

    cout << "Sorted array (Selection Sort): ";
    printArray(data, size);

    return 0;
}