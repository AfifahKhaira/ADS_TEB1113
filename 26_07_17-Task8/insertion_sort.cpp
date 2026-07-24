#include <iostream>
using namespace std;

// Insertion Sort
// Builds the sorted array one element at a time by shifting larger elements to the right
void insertionSort(int arr[], int n) {
    // Start from the second element (index 1); index 0 is trivially sorted by itself
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Value currently being inserted into the sorted sub-array
        int j = i - 1;    // Index of the last element in the sorted portion

        // Shift elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Shift element right
            j--;
        }

        // Place key into its correct sorted position
        arr[j + 1] = key;
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
    int data[] = {45, 12, 89, 33, 7, 62, 21};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);

    insertionSort(data, size);

    cout << "Sorted array (Insertion Sort): ";
    printArray(data, size);

    return 0;
}