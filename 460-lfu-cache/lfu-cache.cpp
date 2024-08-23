class Node {
public:    
    int value;
    int freq;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        freq = 1;
        left = NULL;
        right = NULL;
    }
};

class LFUCache {
private:
    int capacity;
    unordered_map<int,pair<int,Node*>> cache;
    map<int, pair<Node*, Node*>> freqMap;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        cache.clear();
        freqMap.clear();
    }

    void remove(Node* node, int currFreq) {
        Node* head = freqMap[currFreq].first;
        Node* tail = freqMap[currFreq].second;
        if (node == head) {
            if (tail == node) {
                head = NULL;
                tail = NULL;
                freqMap.erase(currFreq);
                node -> left = NULL;
                node -> right = NULL;
                return;
            } else {
                head = node -> right;
                head -> left = NULL;
            }
        } else {
            node -> left -> right = node -> right;
            if (node != tail) {
                node -> right -> left = node -> left;
            } else {
                tail = node -> left;
            }
        }
         node -> left = NULL;
         node -> right = NULL;
         freqMap[currFreq].first = head;
         freqMap[currFreq].second = tail;
    }

    void add(Node* node, int newFreq) {
        if (freqMap.find(newFreq) == freqMap.end()) {
            freqMap[newFreq] = {node, node};
            return;
        }
        Node* head = freqMap[newFreq].first;
        Node* tail = freqMap[newFreq].second;
        node -> right = head;
        head -> left = node;
        head = node;
        freqMap[newFreq].first = head;
        freqMap[newFreq].second = tail;
    }
    
    void updatePos(Node* node) {
        int currFreq = node->freq;
        node->freq++;
        remove(node, currFreq);
        add(node, node->freq);
    }


    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* currNode = cache[key].second;
        updatePos(currNode);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            updatePos(cache[key].second);
        } else {
            if (cache.size() == capacity) {
                auto lfu = freqMap.begin();
                cache.erase(lfu->second.second->value);
                remove(lfu->second.second, lfu->second.second->freq);
            }
            Node* newNode = new Node(key);
            cache[key] = {value, newNode};
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