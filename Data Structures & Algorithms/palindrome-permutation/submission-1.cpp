class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        int odds = 0;
        for(auto& [c, count]: freq)
            odds += count % 2;
        
        return odds <= 1;
    }
};
