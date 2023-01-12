// 1. brut f
// 2. sorting n logn /1
// 3. hash n /n


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int idx = 0; idx < nums.size() - 1; idx++) {
            if(nums[idx] == nums[idx + 1])
                return true;
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto val: nums){
            mp[val]++;
            if (mp[val]==2)return true;
        }
        return false;
    }
};