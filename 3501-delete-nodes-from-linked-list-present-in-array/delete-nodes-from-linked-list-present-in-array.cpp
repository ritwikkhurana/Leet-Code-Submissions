/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for (int i: nums) {
            s.insert(i);
        }
        ListNode *prev=NULL,*curr=head;
        while (curr) {
            if (s.find(curr->val) != s.end()) {
                if (prev==NULL) {
                    curr = curr -> next;
                    head = curr;
                } else {
                    prev -> next = curr -> next;
                    curr = curr -> next;
                }
            } else {
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};