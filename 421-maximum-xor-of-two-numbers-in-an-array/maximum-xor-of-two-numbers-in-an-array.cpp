class Node {
    Node* links[2];
public:
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
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
        for (int i=31 ; i>=0 ; i--) {
            int bit = (num >> i) & 1;
            if (!temp->containsKey(bit)) {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
    }

    int getMaxXOR(int num) {
        int maxXor = 0;
        Node* temp = root;
        for (int i = 31 ; i >= 0 ; i--) {
            int bit = (num >> i) & 1;
            if (temp->containsKey(1-bit)) {
                maxXor = maxXor | (1 << i);
                temp = temp->get(1-bit);
            } else {
                temp = temp->get(bit);
            }
        }
        return maxXor;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int i: nums) {
            trie.insertNum(i);
        }

        int ans = 0;
        for (int i: nums) {
            ans = max(ans, trie.getMaxXOR(i));
        }
        return ans;
    }
};