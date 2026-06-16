class Solution {
    char lower(char c){
        if(c >= 'A' and c <= 'Z')
            return c + ('a' - 'A');
        return c;
    }
    
public:
/*
 i                          
                            j
"Was it a car or a cat I saw?"
*/
    bool isPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j){
            if(not isalnum(s[i]))
                i++;
            else if(not isalnum(s[j]))
                j--;
            else if(lower(s[i++]) != lower(s[j--]))
                return false;
        }
        
        return true;
    }
};
