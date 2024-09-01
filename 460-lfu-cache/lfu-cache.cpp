class Node {
public:
    int key;
    int value;
    int freq;
    Node* left;
    Node* right;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        freq = 1;
    }

};

class LFUCache {
public:
    unordered_map<int,Node*> cache;
    map<int, pair<Node*, Node*>> freqMap;
    int cap;
    LFUCache(int capacity) {
        cap = capacity;
        cache.clear();
        freqMap.clear();
    }

    void remove(Node* node, int oldFreq) {
        Node *head = freqMap[oldFreq].first;
        Node *tail = freqMap[oldFreq].second;
        if (node == head && node == tail) {
            head = NULL;
            tail = NULL;
            freqMap.erase(oldFreq);
            return;
        } else {
            if (node != head) {
                node -> left -> right = node -> right;
            }
            if (node != tail) {
                node -> right -> left = node -> left;
            }
            if (node == head) {
                head = node -> right;
            } else if (node == tail) {
                tail = node -> left;
            }
        }
        node -> left = NULL;
        node -> right = NULL;
        freqMap[oldFreq] = {head,tail};
    }

    void add(Node* node, int newFreq) {
        if (freqMap.find(newFreq) == freqMap.end()) {
            freqMap[newFreq] = {node, node};
        } else {
            Node* head = freqMap[newFreq].first;
            node -> right = head;
            head -> left = node;
            head = node;
            freqMap[newFreq].first = head;
        }
    }

    void updatePos(Node* node) {
        int oldFreq = node->freq;
        node->freq++;
        remove(node, oldFreq);
        add(node, node->freq);
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        updatePos(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            updatePos(node);
        } else {
            if (cache.size() == cap) {
                Node* node = freqMap.begin()->second.second;
                cache.erase(node->key);
                remove(node, node->freq);
            }
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            add(newNode, 1); 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */