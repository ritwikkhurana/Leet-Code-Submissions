class Node {
    Node* children[26];
    bool isLast;
public:
    Node() {
        isLast = false;
        for (int i = 0 ; i < 26 ; i++) {
            children[i] = NULL;
        }
    }

    bool exists(char c) {
        return children[c-'a'] != NULL;
    }

    Node* get(char c) {
        return children[c-'a'];
    }

    Node* create(char c) {
        Node* newNode = new Node();
        children[c-'a'] = newNode;
        return newNode;
    }
    
    void setLastWord() {
        isLast = true;
    }

    bool isLastWord() {
        return isLast;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0;  i < word.size() ; i++) {
            if (node->exists(word[i])) {
                node = node->get(word[i]);
            } else {
                node = node->create(word[i]);
            }
        }
        node->setLastWord();
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0 ; i < word.size() ; i++) {
            if (node->exists(word[i])) {
                node = node->get(word[i]);
            } else {
                return false;
            }
        }
        return node->isLastWord();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0 ; i < prefix.size() ; i++) {
            if (node->exists(prefix[i])) {
                node = node->get(prefix[i]);
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */