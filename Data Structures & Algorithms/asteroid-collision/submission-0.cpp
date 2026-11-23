class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for(int asteroid: asteroids){
            if(asteroid > 0)
                st.push_back(asteroid);
            else{
                // -ve asteroid
                bool destroyed = false;
                while(not st.empty() and st.back()>0 and st.back() <= abs(asteroid)){
                    int top = st.back();
                    st.pop_back();

                    if(top == abs(asteroid)){
                        destroyed = true;
                        break;
                    }
                }
                if(not destroyed and (st.empty() or st.back() < 0))
                    st.push_back(asteroid);
            }
        }

        return st;
    }
};