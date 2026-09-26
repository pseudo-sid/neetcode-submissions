class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> keyIdx;
        for(int i = 0; i < keyboard.length(); i++)
            keyIdx[keyboard[i]] = i;
        
        int time = 0, prevIdx = 0;
        for(char c: word){
            int index = keyIdx[c];
            time += abs(index - prevIdx);
            prevIdx = index;
        }
        
        return time;
    }
};
