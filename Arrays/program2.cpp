// Code to merge two sorted arrays without using extra space.

#include <iostream>
#include <cmath> // For ceil() 

using namespace std;

// Function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2); // ceiling of gap/2
}

void merge(int arr1[], int arr2[], int n, int m) {
    int gap = nextGap(n + m);

    while (gap > 0) {
        int i, j;

        // Compare elements in the first array
        for (i = 0; i + gap < n; i++) {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // Compare elements in both arrays
        for (j = gap > n ? gap - n : 0; i < n && j < m; i++, j++) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // Compare elements in the second array
        if (j < m) {
            for (j = 0; j + gap < m; j++) {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }

        gap = nextGap(gap);
    }
}

int main() {
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    merge(arr1, arr2, n, m);

    cout << "Merged arrays:\n";
    for (int i = 0; i < n; i++) cout << arr1[i] << " ";
    for (int i = 0; i < m; i++) cout << arr2[i] << " ";

    return 0;
}
