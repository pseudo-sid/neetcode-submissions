class Solution {
public:

    string encode(vector<string>& strs) {
        /*
            encoded = "5#Hello5#Hello"
        */
        string encoded = "";
        for(string str: strs){
            encoded += to_string(str.length()) + '#' + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        /*
                    i
                     j
            "5#Hello5#Hello"
        */
        string word;
        vector<string> decoded;
        int wordLen = -1;
        int i = 0;
        int j = 0;
        while(j < s.length()){
            if(s[j] == '#'){
                wordLen = stoi(s.substr(i, j-i));
                decoded.push_back(s.substr(j+1, wordLen));
                j += wordLen;
                i = j+1;
            }
            j++;
        }

        return decoded;
    }
};
