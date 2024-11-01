class Node{
public:
    int val;
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

class MaxStack {
Node* head;
Node* tail;
map<int,vector<Node*>, greater<int>> maxMap;
public:
    MaxStack() {
        head = NULL;
        tail = NULL;
        maxMap.clear();
    }
    
    void removeEle(Node* node) {
        if (node == head) {
            if (node == tail) {
                head = NULL;
                tail = NULL;
            } else {
                head = node -> right;
                head -> left = NULL;
            }
        } else if (node == tail) {
            tail = node -> left;
            tail -> right = NULL;
        } else {
            node -> left -> right = node -> right;
            node -> right -> left = node -> left;
        }
        node -> left = NULL;
        node -> right = NULL;
    }

    void addEle(Node* node) {
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail -> right = node;
            node -> left = tail;
            tail = node;
        }
    }

    void push(int x) {  
        Node* newNode = new Node(x);
        addEle(newNode);
        maxMap[x].push_back(newNode);
    }
    
    int pop() {
        Node* node = tail;
        removeEle(node);
        maxMap[node->val].pop_back();
        if (maxMap[node->val].empty()) maxMap.erase(node->val);
        return node->val;
    }
    
    int top() {
        return tail->val;
    }
    
    int peekMax() {
        return maxMap.begin()->first;
    }
    
    int popMax() {
        Node* node = maxMap.begin()->second.back();
        removeEle(node);
        maxMap.begin()->second.pop_back();
        if (maxMap.begin()->second.empty()) maxMap.erase(maxMap.begin());
        return node->val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */