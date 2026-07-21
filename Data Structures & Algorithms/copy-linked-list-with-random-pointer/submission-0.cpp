/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> newNodes;
        Node* temp = head;

        while(temp){
            newNodes[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        Node* ans = new Node(0);
        Node* temp2 = ans;

        while(temp){
            temp2->next = newNodes[temp];
            temp2->next->random = newNodes[temp->random];

            temp = temp->next;
            temp2 =temp2->next;
        }

        return ans->next;
    }
};
