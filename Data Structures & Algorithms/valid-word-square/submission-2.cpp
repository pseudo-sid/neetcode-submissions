class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if(words.empty()) return true;
        if(words.size() != words[0].size()) return false;

        int n = words.size();
        for(int d = 0; d < n; d++){
            for(int k = 0; k < words[d].size(); k++)
                if(k >= n or d >= words[k].size() or words[d][k] != words[k][d])
                    return false;
        }
        return true;
    }
};
