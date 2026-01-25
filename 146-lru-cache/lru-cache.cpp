class Node {
public:

    int key;
    int value;
    Node* left;
    Node* right;

    Node(int key, int value) {
        this -> key = key;
        this -> value = value;
        this -> left = NULL;
        this -> right = NULL;
    }
};


class LRUCache {
    int cap;
    unordered_map<int, Node*> ourmap;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        if (head == node) {
            head = node -> right;
            if (tail == node) tail = NULL;
        } else if (tail == node) {
            tail = node -> left;
        } else {
            node -> left -> right = node -> right;
            node -> right -> left = node -> left;
        }
        node -> left = NULL;
        node -> right = NULL;
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

    void updatePos(Node* node) {
        remove(node);
        add(node);
    }
    
public:

    LRUCache(int capacity) {
        this -> cap = capacity;
        head = NULL;
        tail = NULL;
        ourmap.clear();
    }

    int get(int key) {
        if (ourmap.find(key) == ourmap.end()) return -1;
        int val = ourmap[key] -> value;
        updatePos(ourmap[key]);
        return val;
    }
    
    void put(int key, int value) {
        if (ourmap.find(key) != ourmap.end()) {
            ourmap[key] -> value = value;
            updatePos(ourmap[key]);
        } else {
            if (ourmap.size() == this -> cap) {
                ourmap.erase(tail -> key);
                remove(tail);
            }
            Node* newNode = new Node(key, value);
            ourmap[key] = newNode;
            add(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */