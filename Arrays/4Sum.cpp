// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int target){
        vector<vector<int>> res;
        int n = nums.size();
        if (n<4) return res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int target_2 = target - nums[i] - nums[j];
                int front = j+1;
                int rear = n-1;
                while(front<rear){
                    int two_sum = nums[front] + nums[rear];
                    if (two_sum<target_2) front++;
                    else if (two_sum>target_2) rear--;
                    else{
                        vector<int> quadruplet(4);
                        quadruplet[0] = nums[i];
                        quadruplet[1] = nums[j];
                        quadruplet[2] = nums[front];
                        quadruplet[3] = nums[rear];
                        res.push_back(quadruplet);

                        int front_back = front, rear_back = rear;
                        while(front<rear && nums[front]==nums[front_back]) front++;
                        while(front<rear && nums[rear]==nums[rear_back]) rear--; 
                    }
                }
                while(j+1<n && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<n && nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};

int main(){
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    Solution s;
    vector<vector<int>> result = s.fourSum(nums, target);
    for(const auto& quad : result){
        for(int val : quad){
            cout << val << " ";
        }
        cout << endl;
    }
}