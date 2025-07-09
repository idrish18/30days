#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> numMap; 
    
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
    
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
    
            numMap[nums[i]] = i;
        }
    
        return {};
        }
    };

    int main(){
        vector<int> v={1,2,3,4,5,1};
        int target=5;
        Solution s;
        s.twoSum(v,target);
        return 0;
    }