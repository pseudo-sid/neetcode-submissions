class Solution {
    /*  
               r
        [2,4,5,8]
         l
    */
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int r = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int l = r-1;

        while(l >= 0 and r < arr.size() and k--){
            if(abs(arr[l] - x) <= abs(arr[r] - x))
                l--;
            else
                r++;
        }

        while(l >= 0 and k-- > 0)
            l--;

        
        while(r < arr.size() and k-- > 0)
            r++;
        
        return vector<int>(arr.begin() + l+1, arr.begin() + r);

    }
};