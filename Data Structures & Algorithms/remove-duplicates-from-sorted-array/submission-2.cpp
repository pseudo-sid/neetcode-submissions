class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int idx = 1; idx < nums.size(); idx++){
            if(nums[idx] == nums[idx-1])
                continue;
            
            nums[++k] = nums[idx];
        }
        return k+1;
    }
};