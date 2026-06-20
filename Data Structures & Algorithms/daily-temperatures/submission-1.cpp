class Solution {
    /*
        st = [[58, 3] [76, 7], [100, 8]]                  
                        i
        res = [0, 0, 0, 4, 3, 2, 1, 1, 0, 0]
               0  1  2  3  4  5  6  7  8  9

                  i
        [89,62,70,58,47,47,46,76,100,70]
         0   1  2  3  4  5  6  7  8   9
    */
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i = n-1; i >= 0; i--){
            while(not st.empty() and st.top().first <= temperatures[i])
                st.pop();

            if(not st.empty())
                res[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }
        return res;
    }
};
