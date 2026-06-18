class Solution {
    /*

    freq = {
        'A': 3,
        'B': 3,
    }
    windowLen - count[B] <= k
    
          l
              r
        "ABABBA"
    */
public:
    int getMaxFreq(unordered_map<int, int> freq){
        int ans = 0;
        for(pair<int, int> p: freq)
            ans = max(ans, p.second);

        return ans;
    }

    int characterReplacement(string s, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int ans = 0;
        
        for(int right = 0; right < s.length(); right++){
            freq[s[right]]++;
            while((right - left + 1) - getMaxFreq(freq) > k)
                freq[s[left++]]--;
            
            ans = max(ans, right-left+1);
        }

        return ans;

    }
};
