class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int first = 0;
        for(int curr = 0; curr < nums.size(); curr++)
            if(nums[curr] != val)
                swap(nums[curr], nums[first++]);
        
        return first;
    }
};