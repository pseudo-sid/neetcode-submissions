class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(string operation: operations){
            if(operation == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push(y);
                st.push(x);
                st.push(x+y);
            }
            else if (operation == "D")
                st.push(2*st.top());

            else if(operation == "C")
                st.pop();
            else
                st.push(stoi(operation));
        }

        int ans = 0;
        while(not st.empty()){
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};