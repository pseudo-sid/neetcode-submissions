class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> candidates;
        for(int num: nums){
            candidates[num]++;
            if(candidates.size() <= 2)
                continue;
            
            unordered_map<int, int> newCount;
            for(pair<int, int> it : candidates){
                if(it.second > 1)
                    newCount[it.first] = it.second-1;
            }

            candidates = newCount;
        }

        vector<int> res;

        for(auto it: candidates){
            if(count(nums.begin(), nums.end(), it.first) > nums.size()/3)
                res.push_back(it.first);
        }

        return res;
    }
};