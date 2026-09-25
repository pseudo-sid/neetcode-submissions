class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, list<int>> nums2Idx;
        int n = nums1.size();
        for(int idx = 0; idx < n; idx++)
            nums2Idx[nums2[idx]].push_back(idx);
            
        vector<int> mapping(n);
        for(int i = 0; i < n; i++){
            mapping[i] = nums2Idx[nums1[i]].front();
            nums2Idx[nums1[i]].pop_front();
        }

        return mapping;
    }
};
