class Node {
public:
    int val;
    Node *left;
    Node *right;

    Node(int value) {
        val = value;
        left = NULL;
        right = NULL;
    }
};
class LRUCache {
private:
    int capacity;
    unordered_map<int,pair<int,Node*>> cache;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        head = NULL;
        tail = NULL;
    }

    void updatePos(Node *currNode) {
        if (currNode != head) {
            currNode -> left -> right = currNode -> right;
            if (currNode == tail) {
                tail = currNode -> left;
            } else {
                currNode -> right -> left = currNode -> left;
            }
            currNode -> left = NULL;
            currNode -> right = head;
            head -> left = currNode;
            head = currNode;
        }
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* currNode = cache[key].second;
        updatePos(currNode);
        return cache[key].first;
    }

    void removeLRU() {
        if (head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail -> left -> right = NULL;
            tail = tail -> left;
        }
    }

    void addNode(int key, int value) {
        Node* newNode = new Node(key);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode -> right = head;
            head -> left = newNode;
            head = newNode;
        }
        cache[key] = {value, newNode};
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            updatePos(cache[key].second);
        } else {
            if (cache.size() == capacity) {
                cache.erase(tail->val);
                removeLRU();
            }
            addNode(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */