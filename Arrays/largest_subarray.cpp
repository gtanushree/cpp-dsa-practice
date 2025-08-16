// Time: O(nlogn), Space: O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int maxLen(vector<int> &nums){
    int n = nums.size();
    int maxi = 0;
    int sum = 0;
    unordered_map<int, int> mpp;
    for (int i=0; i<n; i++){
        sum+=nums[i];
        if (sum==0) maxi=i+1;
        else{
            if (mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i-mpp[sum]);
            }
            else mpp[sum]=i;
        }
    }
    return maxi;
};

int main(){
    vector<int> nums = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    int result = maxLen(nums);
    cout << "Length of the largest subarray: " << result << endl;
}