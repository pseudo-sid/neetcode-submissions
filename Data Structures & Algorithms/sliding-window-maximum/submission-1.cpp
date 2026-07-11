class Solution {
    /*
        [1,3,1,2,0,5] k= 3

        q = [2, 0]

        ans = [3, 3, 2]
    */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            if(not q.empty() and q.front() <= i-k)
                q.pop_front();

            while(not q.empty() and nums[i] > nums[q.back()])
                q.pop_back();

            q.push_back(i);
        
            
            
            if(i >= k-1)
                ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};
