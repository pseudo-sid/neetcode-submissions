class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_multiset<int> s(nums.begin(), nums.end());
        int largest = INT_MIN;

        for(int num: s)
            if(s.count(num) == 1 and num > largest)
                largest = num;
        
        return largest == INT_MIN ? -1 : largest;
        
    }
};

/*
unordered_multiset
[5,7,3,9,4,9,8,3,1]


*/