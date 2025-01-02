class Node {
    Node* links[2];
public:
    Node* getNode(int bit) {
        return links[bit];
    }

    void setNode(int bit, Node* node) {
        links[bit] = node;
    }

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
};

class Trie {
    Node* root;
public:

    Trie() {
        root = new Node();
    }

    void insertNum(int num) {
        Node* temp = root;
        for (int i = 31 ; i >= 0 ; i--) {
            int bit = (num>>i) & 1;
            if (!temp->containsKey(bit)) {
                Node* newNode = new Node();
                temp->setNode(bit, newNode);
            }
            temp = temp->getNode(bit);
        }
    }

    int findMaxVal(int num) {
        Node* temp = root;
        int xorVal = 0;
        for (int i = 31 ; i>=0 ; i--) {
            int bit = (num>>i) & 1;
            if (temp->containsKey(1-bit)) {
                temp = temp->getNode(1-bit);
                xorVal =  (1 << i) | xorVal;
            } else {
                temp = temp->getNode(bit);
            }
        }
        return xorVal;
    }
};





class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int maxXor = 0;
        for (int i = 0 ; i < nums.size() ; i++) {
            trie.insertNum(nums[i]);
        }

        for (int i = 0 ; i < nums.size() ; i++) {
            int xorVal = trie.findMaxVal(nums[i]);
            maxXor = max(maxXor, xorVal);
        }
        return maxXor;
    }
};