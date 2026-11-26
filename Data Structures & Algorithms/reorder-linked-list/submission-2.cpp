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
     s
              f
[2,4,6,8, 10]
*/
class Solution {
    ListNode* reverse(ListNode* head){
        if(not head)
            return nullptr;
        
        ListNode* t1 = head, *t2 = head->next;
        t1->next = nullptr;

        while(t2){
            ListNode* t3 = t2->next;
            t2->next = t1;
            t1 = t2;
            t2 = t3;
        }

        return t1;
    }

public:
    void reorderList(ListNode* head) {
        if(not head or not head->next)
            return;
        ListNode* slow = head, *fast = head->next;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = reverse(slow->next);
        slow->next = nullptr;

        cout << head2->val;
        ListNode* ans = new ListNode();

        ListNode* t = ans;

        while(head2){
            t->next = head;
            head = head->next;
            t = t->next;

            t->next = head2;
            head2 = head2->next;
            t = t->next;
        }
        t->next = head;

    }
};
