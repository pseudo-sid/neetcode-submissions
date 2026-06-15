class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int maxFreq = 0;
        for(int num: nums)
            maxFreq = max(maxFreq, ++freq[num]);
        
        vector<list<int>> buckets(maxFreq+1);
        for(int num: nums){
            if(freq.find(num) != freq.end()){
                buckets[freq[num]].push_back(num);
                freq.erase(num);
            }
        }

        int bucket = maxFreq;
        vector<int> res;
        for(int bucket = maxFreq; bucket > 0; bucket--){
            for(int num: buckets[bucket]){
                if(res.size() == k)
                    break;
                res.push_back(num);
            }
        }

        return res;
    }
};
