class Node{
    public:
        string url;
        Node* next, *prev;
        Node(string url){
            this->url = url;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class BrowserHistory {
    Node* curr;
public:
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        Node* node = new Node(url);
        node->prev = curr;
        curr->next = node;
        curr = node;
    }
    
    string back(int steps) {
        while(curr->prev and steps--)
            curr = curr->prev;
        return curr->url;
    }
    
    string forward(int steps) {
        while(curr->next and steps--)
            curr = curr->next;
        
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */