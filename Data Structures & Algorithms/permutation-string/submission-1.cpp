class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n2 < n1)
            return false;
        
        
        vector<int> f1(128, 0), f2(128, 0);
        auto equals = [&](){
            for(int i = 0; i < 128; i++)
                if(f1[i] != f2[i])
                    return false;
            return true;
        };

        for(int i = 0; i < n1; i++)
            f1[s1[i]]++;

        for(int i = 0; i < n2; i++){
            f2[s2[i]]++;
            if(equals())
                return true;
            if(i >= n1-1)
                f2[s2[i - n1 +1]]--;
        }

        return false;
    }
};
