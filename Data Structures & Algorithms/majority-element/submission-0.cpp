class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int freq = 1;

        for(int x: nums){
            if(x == maj)
                freq++;
            else
                freq--;
            
            if(freq == 0){
                maj = x;
                freq = 1;
            }
        }

        return maj;
    }
};