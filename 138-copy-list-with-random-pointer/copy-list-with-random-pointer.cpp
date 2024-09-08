/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToNew;
        unordered_map<Node*, Node*> newToOld;
        Node *newHead = NULL;
        Node* temp = head;
        Node* prev = NULL;
        while (temp) {
            Node* newNode = new Node(temp->val);
            if (newHead == NULL) newHead = newNode;
            if (prev) {
                prev -> next = newNode;
            }
            prev = newNode;
            oldToNew[temp] = newNode;
            newToOld[newNode] = temp;
            temp = temp -> next;
        }

        temp = newHead;
        while(temp) {
            Node* oldRandom = newToOld[temp]->random;
            if (oldRandom) {
                temp->random = oldToNew[oldRandom];
            }
            temp = temp -> next;
        }
        return newHead;
    }
};