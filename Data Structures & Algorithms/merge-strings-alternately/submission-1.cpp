class Solution {
public:
    string mergeAlternately(string word1, string word2) { 
        string merged;
        int i;        
        for(i = 0; i < min(word1.length(), word2.length()); i++){
            merged += word1[i];
            merged += word2[i];
        }

        return merged + word1.substr(i) + word2.substr(i);
    }
};