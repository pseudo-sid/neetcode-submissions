class Solution {
    bool compare(vector<int>& freq1, vector<int>& freq2){
        for(int i = 0; i < 128; i++)
            if(freq1[i] != freq2[i])
                return false;
        
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(128, 0), freq2(128, 0);
        int left = 0;
        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i]]++;
            freq2[s2[i]]++;
        }
        
        for(int right = s1.length(); right < s2.length(); right++){
            if(compare(freq1, freq2))
                return true;
                
            freq2[s2[left++]]--;
            freq2[s2[right]]++;
        }

        return compare(freq1, freq2);
        

    }
};
