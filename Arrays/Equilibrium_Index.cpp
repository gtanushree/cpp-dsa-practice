// Code to find equilibrium index of an array
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

int equilibriumIndex(vector<int>& arr) {
    int totalSum = 0;
    for (int val : arr) totalSum += val;

    int leftSum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int rightSum = totalSum - leftSum - arr[i];
        if (leftSum == rightSum)
            return i;
        leftSum += arr[i];
    }

    return -1; 
}

int main() {
    vector<int> arr = {-7, 1, 5, 2, -4, 3, 0};
    int index = equilibriumIndex(arr);

    if (index != -1)
        cout << "Equilibrium Index: " << index << endl;
    else
        cout << "No Equilibrium Index found." << endl;

    return 0;
}
