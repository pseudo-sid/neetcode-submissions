class Solution {
    int maxFreq(vector<int>& charFreq){
        int ans = INT_MIN;
        for(int freq: charFreq)
            ans = max(ans, freq);
        
        return ans;
    }


public:
    int characterReplacement(string s, int k) {
        int left = 0; 
        vector<int> charFreq(128, 0);
        int ans = 0;

        for(int right = 0; right < s.length(); right++){
            charFreq[s[right]]++;
            while((right-left+1) - maxFreq(charFreq) > k)
                charFreq[s[left++]]--;
            
            ans = max(ans, right-left+1);
        }

        return ans;
    }
};
