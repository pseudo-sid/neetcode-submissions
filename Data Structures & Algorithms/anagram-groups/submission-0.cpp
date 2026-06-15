class Solution {
    string compressedCode(string &str){
        vector<int> freq(26, 0);
        string code = "";

        for(char c: str)
            freq[c-'a']++;
        
        for(int i = 0; i < 26; i++)
            if(freq[i])
                code += string(1, 'a'+i) + to_string(freq[i]);
        
        return code;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> groups;
        for(string str: strs)
            groups[compressedCode(str)].push_back(str);
        
        for(pair<string, vector<string>> p: groups)
            res.push_back(p.second);

        return res;

    }
};
