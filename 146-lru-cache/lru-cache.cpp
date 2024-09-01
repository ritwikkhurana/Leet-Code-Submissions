class Node{
public:
    int key;
    int val;
    Node *left;
    Node *right;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> cache;
    int cap;
    Node* head;
    Node* tail;
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
        cache.clear();
    }

    void updatePos(Node* node) {
        if (node != head) {
            node -> left -> right = node -> right;
            if (node == tail) {
                tail = node -> left;
            } else {
                node -> right -> left = node -> left;
            }
            node -> left = NULL;
            add(node);
        }
    }
    
    void remove() {
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail -> left -> right = NULL;
            tail = tail -> left;
        }
    }

    void add(Node* node) {
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            node -> right = head;
            head -> left = node;
            head = node;
        }
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        updatePos(node);
        return cache[key]->val;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->val = value;
            updatePos(node);
        } else {
            if (cache.size() == cap) {
                cache.erase(tail->key);
                remove();
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            add(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */