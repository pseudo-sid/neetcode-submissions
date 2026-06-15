class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colors(3, 0);
        for(int x: nums)
            colors[x]++;
        
        int idx = 0;
        for(int i = 0; i < 3; i++)
            while(colors[i]--)
                nums[idx++] = i;
    }
};