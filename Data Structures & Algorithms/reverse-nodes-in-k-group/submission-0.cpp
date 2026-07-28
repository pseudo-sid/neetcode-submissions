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

/*

prev = nullptr

f
          r
               n
1 -> 2 -> 3 -> 4 -> 5 
*/
class Solution {
    void reverse(ListNode* head){
        if(not (head and head->next))
            return;
        
        ListNode* t1 = head,  *t2 = head->next;
        head->next = nullptr;

        while(t2){
            ListNode* t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // ListNode* reversedHead = reverse(head);
        int curr_length = 0;
        ListNode* ans = new ListNode(0, head);
        ListNode* prev = ans, * curr = head;

        while(curr){
            /*
            curr_len = 3
             p            c  t
                1 -> 2- > 3  4 -> 5 
            */
            if(++curr_length == k){
                curr_length = 0;
                ListNode* temp = curr->next;
                curr->next = nullptr;
                reverse(prev->next);
                ListNode* newEnd = prev->next;
                prev->next = curr;
                prev = newEnd;
                prev->next = temp;
                curr = prev;
            }
            curr = curr->next;
        }

        return ans->next;

    }
};
