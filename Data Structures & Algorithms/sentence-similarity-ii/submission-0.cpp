class DSU{
    unordered_map<string, string> parent;
    unordered_map<string, int> rank;
    public:
        // DSU(int n){
        //     this->n = n;
        //     for(int i = 0; i < n; i++){
        //         parents.push_back(i);
        //         ranks[i] = 0;
        //     }
        // }
    
    void add(string s){
        if(parent.find(s) == parent.end()){
            parent[s] = s;
            rank[s] = 0;
        }
    }

    string find(string s){
        if(s != parent[s])
            parent[s] = find(parent[s]);
        
        return parent[s];
    }

    bool isWordPresent(string x){
        return parent.find(x) != parent.end();
    }

    void unionByRank(string s1, string s2){
        string s1Set = find(s1), s2Set = find(s2);
        if(s1Set == s2Set)
            return;
        
        if(rank[s1Set] < rank[s2Set])
            parent[s1Set] = s2Set;
        else if(rank[s1Set] > rank[s2Set])
            parent[s2Set] = s1Set;
        else{
            parent[s2Set] = s1Set;
            rank[s2Set]++;
        }
    }

};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if(sentence1.size() != sentence2.size()) return false;

        DSU dsu;

        for(vector<string>& words: similarPairs){
            dsu.add(words[0]);
            dsu.add(words[1]);
            dsu.unionByRank(words[0], words[1]);
        }

        for(int i = 0; i < sentence1.size(); i++){
            if(sentence1[i] == sentence2[i])
                continue;

            if(dsu.isWordPresent(sentence1[i]) and dsu.isWordPresent(sentence2[i]) and dsu.find(sentence1[i]) == dsu.find(sentence2[i]))
                continue;
            
            return false;
        }

        return true;
    }
};
