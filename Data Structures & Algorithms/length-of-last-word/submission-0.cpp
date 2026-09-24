class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.length()-1;
        while(s[idx] == ' ')idx--;
        int back = idx;
        while(idx>=0 and s[idx] != ' ')
            idx--;
        
        return back-idx;
    }
};