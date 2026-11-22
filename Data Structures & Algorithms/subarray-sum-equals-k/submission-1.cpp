class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix_count;
        int prefix_sum = 0;
        prefix_count[0] = 1;
        int ans = 0;

        for(int num: nums){
            prefix_sum += num;
            ans += prefix_count[prefix_sum - k];
            prefix_count[prefix_sum]++;
        }

        return ans;
    }
};