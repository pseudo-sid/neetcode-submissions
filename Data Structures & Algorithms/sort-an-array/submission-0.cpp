class Solution {
    void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp(right-left+1);
        int l = left, r = mid+1;
        int idx = 0;
        while(l <= mid and r <= right){
            if(nums[l] <= nums[r])
                temp[idx++] = nums[l++];
            else
                temp[idx++] = nums[r++];
        }
        while(l <= mid)
            temp[idx++] = nums[l++];
        
        while(r <= right)
            temp[idx++] = nums[r++];
        
        for(int i = left; i <= right; i++)
            nums[i] = temp[i-left];
    }

    void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
        
        int mid = (right-left)/2 + left;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};