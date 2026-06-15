class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0] = {""};

        for(int i = 1; i <= n; i++)
            for(int j = 0; j < i; j++)
                for(string& left: dp[i-j-1])
                    for(string& right: dp[j])
                        dp[i].push_back("(" + left + ")" + right);
        
        return dp[n];
    }
};
