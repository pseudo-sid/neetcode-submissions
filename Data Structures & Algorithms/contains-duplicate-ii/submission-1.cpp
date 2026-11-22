class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> prevIdx;
        for(int i = 0; i < nums.size(); i++){
            if(prevIdx.count(nums[i]) and i - prevIdx[nums[i]] <= k)
                return true;
            prevIdx[nums[i]] = i;
        }

        return false;
    }
};