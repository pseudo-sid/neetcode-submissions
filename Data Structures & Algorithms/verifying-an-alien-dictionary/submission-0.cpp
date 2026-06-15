class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderMap(26);
        for(int i = 0; i < order.length(); i++)
            orderMap[order[i] - 'a'] = i;
        
        for(int i = 0; i < words.size()-1; i++){
            for(int idx = 0; idx < words[i].length(); idx++){
                if(idx == words[i+1].length())
                    return false;
                if(orderMap[words[i][idx]-'a'] > orderMap[words[i+1][idx]-'a'])
                    return false;
                if(words[i][idx] != words[i+1][idx])
                    break;
            }
        }

        return true;
    }
};