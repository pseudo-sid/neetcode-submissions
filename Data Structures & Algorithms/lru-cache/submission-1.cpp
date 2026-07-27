class Node{
    public:
        int key, val;
        Node *next, *prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = nullptr;
            prev = nullptr;
        }
};

class LRUCache {
    unordered_map<int, Node*> cache;
    Node *mostFreq, *leastFreq;
    int capacity, size;

public:
    LRUCache(int capacity) {
        this->size = 0;
        this->capacity = capacity;
        mostFreq = nullptr;
        leastFreq = nullptr;
    }

    void updateMostFreq(Node* node){
        if(mostFreq == nullptr){
            mostFreq = node;
            leastFreq = node;
            return;
        }
        if(node == mostFreq)
            return;
        
        if(leastFreq == node and leastFreq->next)
            leastFreq = leastFreq->next;
        if(node->prev)
            node->prev->next = node->next;
        
        if(node->next)
            node->next->prev = node->prev;
        
        node->prev = mostFreq;
        node->next = nullptr;
        mostFreq->next = node;
        mostFreq = node;
    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;

        updateMostFreq(cache[key]);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if(cache.find(key) == cache.end()){
            cache[key] = new Node(key, value);
            this->size++;
            if(this->size > this->capacity){
                cache.erase(this->leastFreq->key);
                this->leastFreq = this->leastFreq->next;
            }
        }
        else
            cache[key]->val = value;
        updateMostFreq(cache[key]);
    }
};
