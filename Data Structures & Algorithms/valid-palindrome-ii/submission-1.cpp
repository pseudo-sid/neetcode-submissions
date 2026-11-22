class Solution {
    bool isValid(string& s, int l, int r, bool deleteAllowed = false){
        while(l < r){
            if(s[l] != s[r]){
                if(deleteAllowed)
                    return isValid(s, l+1, r) or isValid(s, l, r-1);
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
public: 
    bool validPalindrome(string s) {
        return isValid(s, 0, s.length()-1, true);
    }
};