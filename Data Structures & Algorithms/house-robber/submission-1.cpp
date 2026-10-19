class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        for(int i = nums.size()-1; i >= 0; i--){
            int curr = max(rob1, rob2 + nums[i]);
            rob2 = rob1;
            rob1 = curr;
        }

        return rob1;
    }
};
