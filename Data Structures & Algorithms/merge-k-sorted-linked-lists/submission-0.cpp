/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    ListNode* mergeSort(vector<ListNode*>& lists, int low, int high){
        if(low == high)
            return lists[low];
        if(low > high)
            return nullptr;
        
        int mid = (high-low)/2 + low;

        ListNode* left = mergeSort(lists, low, mid);
        ListNode* right = mergeSort(lists, mid+1, high);

        ListNode* merged = new ListNode();
        ListNode* t = merged;

        while(left and right){
            if(left->val < right->val){
                t->next = left;
                left = left->next;
            }
            else{
                t->next = right;
                right = right->next;
            }
            t = t->next;
        }

        if(left)
            t->next = left;
        else
            t->next = right;
        
        return merged->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeSort(lists, 0, lists.size()-1);
    }
};
