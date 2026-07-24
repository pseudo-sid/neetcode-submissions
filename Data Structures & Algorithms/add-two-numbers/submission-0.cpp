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
    int len(ListNode* node){
        int length = 0;
        while(node){
            length++;
            node = node->next;
        }

        return length;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(len(l1) < len(l2))
            return addTwoNumbers(l2, l1);
        ListNode* head = l1;
        ListNode* temp = l1;
        int carry = 0;
        while(l1 or carry){
            l1->val += (l2 ? l2->val: 0) + carry;
            carry = l1->val/10;
            l1->val %= 10;
            if(not l1->next and carry){
                l1->next = new ListNode(carry);
                break;
            }
            l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }

        return head;
    }
};
