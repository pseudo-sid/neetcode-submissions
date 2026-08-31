class Solution {
public:
    vector<int> prefix;
    Solution(vector<int>& w) {
        prefix = {0};
        for(int wt: w)
            prefix.push_back(prefix.back() + wt);
    }
    
    int pickIndex() {
        double target = prefix.back() * ((double) rand() / RAND_MAX);
        auto it = upper_bound(prefix.begin(), prefix.end(), target);
        return it - prefix.begin()-1;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */