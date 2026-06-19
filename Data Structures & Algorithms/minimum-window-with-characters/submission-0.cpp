class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tFreq, window;
        for(char c: t)
            tFreq[c]++;
        
        int ansL = 0, ansR = INT_MAX;
        int left = 0, charsCovered = 0;

        for(int right = 0; right < s.length(); right++){
            if(tFreq.find(s[right]) != tFreq.end() and ++window[s[right]] == tFreq[s[right]])
                charsCovered++;

            while(charsCovered == tFreq.size()){
                if(right - left < ansR - ansL){
                    ansL = left;
                    ansR = right;
                }

                if(tFreq.find(s[left]) != tFreq.end() and --window[s[left]] < tFreq[s[left]])
                    charsCovered--;
                left++;
            }
        }

        return ansR == INT_MAX ? "" : s.substr(ansL, ansR - ansL+1);


    }
};
