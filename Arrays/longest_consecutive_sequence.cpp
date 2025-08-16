// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution{
    public:
    int longestSequence(vector<int> &nums){
        set<int> hashSet;
        for (int num : nums){
            hashSet.insert(num);
        }
        int longestStreak = 0;
        for (int num : nums){
            if(!hashSet.count(num-1)){
                int currentNum = num;
                int currentStreak = 1;
                while(hashSet.count(currentNum+1)){
                    currentNum+=1;
                    currentStreak+=1;
                }
                longestStreak = max(currentStreak, longestStreak);
            }
        }
        return longestStreak;
    }
};

int main(){
    vector<int> nums = {0, 3, 90, 4, 5, 91, 89, 1, 93, 2, 92, 94, 95};
    Solution s;
    int result = s.longestSequence(nums);
    cout << "length of longest consecutive sequence: " << result << endl;
}