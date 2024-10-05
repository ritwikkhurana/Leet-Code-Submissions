class Node {
    Node* links[2];
public:
    int minNumber = INT_MAX;
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
            temp->minNumber = min(num, temp->minNumber);
            int bit = (num >> i) & 1;
            if (!temp->containsKey(bit)) {
                temp->put(bit, new Node());
            }
            temp = temp->get(bit);
        }
        temp->minNumber = min(num, temp->minNumber);
    }

    int getMaxXOR(int num, int limit) {
        int maxXor = 0;
        Node* temp = root;
        for (int i = 31 ; i >= 0 ; i--) {
            int bit = (num >> i) & 1;
            if (temp->containsKey(1-bit) && temp->get(1-bit)->minNumber <= limit) {
                maxXor = maxXor | (1 << i);
                temp = temp->get(1-bit);
            } else if (temp->get(bit)->minNumber <= limit){
                temp = temp->get(bit);
            } else {
                return -1;
            }
        }
        return maxXor;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> output;
        Trie trie;
        for (int i = 0 ; i < nums.size() ; i++) {
            trie.insertNum(nums[i]);
        }

        for (auto i: queries) {
            output.push_back(trie.getMaxXOR(i[0], i[1]));
        }
        return output;
    }
};