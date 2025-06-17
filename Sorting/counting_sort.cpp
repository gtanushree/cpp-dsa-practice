// Counting Sort is a non-comparison-based sorting algorithm. 
// It works efficiently when the range of input data (max - min) is not significantly larger than the number of elements to sort.
// It counts the occurrences of each element and then computes the position of each element in the sorted array.

// Code to implement Counting Sort on an unsorted array.
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxElem = *max_element(arr.begin(), arr.end());
    int minElem = *min_element(arr.begin(), arr.end());
    int range = maxElem - minElem + 1;

    vector<int> count(range, 0);        
    vector<int> output(arr.size());     

    for (int num : arr)
        count[num - minElem]++;

    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - minElem] - 1] = arr[i];
        count[arr[i] - minElem]--;
    }

    arr = output;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    cout<< "Orignal array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
