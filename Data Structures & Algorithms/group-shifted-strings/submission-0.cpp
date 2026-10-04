class Solution {
    string first_a_convert(string& s){
        int diff = s[0] - 'a';
        string ans;
        for(char c: s){
            char diffed = c - diff;
            if(diffed < 'a')
                diffed += 26;
            
            ans += string(1, diffed);
        }

        return ans;
    }

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> groups;

        for(string s: strings)
            groups[first_a_convert(s)].push_back(s);
        
        vector<vector<string>> res;

        for(pair<string, vector<string>> p: groups){
            res.push_back(p.second);
        }

        return res;

    }
};
