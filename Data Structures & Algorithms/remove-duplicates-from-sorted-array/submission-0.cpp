class Solution {
    /*         l
                          r
        [2,10,30,30,30,30]
    */
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] != nums[left])
                nums[++left] = nums[right];
        }

        return left +1;
    }
};