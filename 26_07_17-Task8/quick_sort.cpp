#include <iostream>
#include <utility> // For std::swap
using namespace std;

// Partition function using the first element as the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Select the first element as the pivot
    int i = low + 1;      // Pointer starting right after the pivot
    int j = high;         // Pointer starting from the end of the sub-array

    while (i <= j) {
        // Move 'i' right while elements are smaller than or equal to pivot
        while (i <= high && arr[i] <= pivot) {
            i++;
        }

        // Move 'j' left while elements are strictly greater than pivot
        while (j >= low + 1 && arr[j] > pivot) {
            j--;
        }

        // Swap out-of-place elements if pointers haven't crossed
        if (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Place the pivot in its final sorted position (at index j)
    swap(arr[low], arr[j]);
    return j; // Return final index of the pivot
}

// Recursive Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array around pivot index
        int pivotIndex = partition(arr, low, high);

        // Recursively sort sub-arrays on left and right of pivot
        quickSort(arr, low, pivotIndex - 1);  // Left sub-array
        quickSort(arr, pivotIndex + 1, high); // Right sub-array
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
    int data[] = {42, 17, 88, 13, 65, 29, 74};
    int size = sizeof(data) / sizeof(data[0]);

    cout << "Original array: ";
    printArray(data, size);

    // Call quickSort passing low index (0) and high index (size - 1)
    quickSort(data, 0, size - 1);

    cout << "Sorted array (Quick Sort): ";
    printArray(data, size);

    return 0;
}