class Solution {
public:
    int appendCharacters(string s, string t) {
        int tPointer = 0;
        for(int i = 0; i < s.length(); i++)
            if(s[i] == t[tPointer])
                tPointer++;
        
        return t.length() - tPointer;
    }
};