class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int curr_sum = 0;
        int ans = INT_MAX;  
        for(int right = 0;  right < nums.size(); right++){
            curr_sum += nums[right];
            while(curr_sum >= target){
                ans = min(ans, right-left+1);
                curr_sum -= nums[left++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};