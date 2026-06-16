class Solution {
    /*
         x
        [2,20,4,10,3,4,5]
    */
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for(int x: nums){
            if(s.find(x-1) == s.end()){
                int y = x;
                while(s.find(++y) != s.end());
                longest = max(longest, y - x);
            }
        }

        return longest;
    }
};
