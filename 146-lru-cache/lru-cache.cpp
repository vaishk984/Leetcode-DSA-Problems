class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key = k;
            val = v;
            prev = next = NULL;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int limit;

    unordered_map<int, Node*> m;

    void delNode(Node* oldNode){
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        delNode(ansNode);
        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int val) {
        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size()==limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */