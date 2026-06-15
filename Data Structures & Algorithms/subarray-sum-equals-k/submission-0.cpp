class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        prefix_count[0] = 1;

        int prefix_sum = 0;
        int ans = 0;
        for(int x: nums){
            prefix_sum += x;
            ans += prefix_count[prefix_sum-k];
            prefix_count[prefix_sum]++;
        }

        return ans;
    }
};