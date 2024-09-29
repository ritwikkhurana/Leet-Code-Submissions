class Node {
public:
    Node* left;
    Node* right;
    string val;
    int count;

    Node(string val) {
        left = NULL;
        right = NULL;
        this->val = val;
        count = 1;
    }
};

class AllOne {
unordered_map<string,Node*> stringCount;
map<int,pair<Node*,Node*>> countMap;
Node* maxKey = NULL;
Node* minKey = NULL;
public:
    AllOne() {
        maxKey = NULL;
        minKey = NULL;
        stringCount.clear();
        countMap.clear();
    }

    void removeNode(int count, Node* node) {
        if (countMap.find(count) == countMap.end()) return;
        Node* head = countMap[count].first;
        Node* tail = countMap[count].second;
        if (head == tail) {
            countMap.erase(count);
        } else {
            if (node == head) {
                head = node->right;
                head->left = NULL;
            } else if (node == tail) {
                tail = node->left;
                tail->right = NULL;
            } else {
                node->left->right = node->right;
                node->right->left = node->left;
            }
            node->left = NULL;
            node->right = NULL;
            countMap[count] = {head, tail};
        }
    }

    void addNode(int count, Node* node) {
        if (count == 0) return;
        if (countMap.find(count) == countMap.end()) {
            countMap[count] = {node, node};
        } else {
            Node* tail = countMap[count].second;
            tail -> right = node;
            node -> left = tail;
            tail = node;
            countMap[count].second = tail;   
        }
    }

    void updateCountMap(int oldCount, int newCount, Node* node) {
        removeNode(oldCount, node);
        addNode(node->count, node);
    }
    
    void inc(string key) {
        if (stringCount.find(key) == stringCount.end()) {
            Node* newNode = new Node(key);
            addNode(newNode->count, newNode);
            stringCount[key] = newNode;
        } else {
            Node* node = stringCount[key];
            int oldCount = node->count;
            int newCount = ++node->count;
            updateCountMap(oldCount, newCount, node);
        }
        updateMinMax();
    }
    
    void dec(string key) {
        Node* node = stringCount[key];
        int oldCount = node->count;
        int newCount = --node->count;
        updateCountMap(oldCount, newCount, node);
        updateMinMax();
    }

    void updateMinMax() {
       if (countMap.size() > 0) {
            minKey = countMap.begin()->second.first;
            maxKey = countMap.rbegin()->second.first;
        } else {
            minKey = NULL;
            maxKey = NULL;
        } 
    }
    
    string getMaxKey() {
        if (maxKey == NULL) return "";
        return maxKey->val;
    }
    
    string getMinKey() {
        if (minKey == NULL) return "";
        return minKey->val;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */