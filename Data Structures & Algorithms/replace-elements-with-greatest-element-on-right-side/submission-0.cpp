class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int greatestElement = arr.back();
        int n = arr.size();
        arr[n-1] = -1;
        for(int i = n-2; i >= 0; i--){
            int temp = arr[i];
            arr[i] = greatestElement;
            greatestElement = max(greatestElement, temp);
        }

        return arr;
    }
};