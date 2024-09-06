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
        unordered_set<int> val;
        for (int i: nums) val.insert(i);
        ListNode* temp=head;
        ListNode* prev = NULL;
        while (temp) {
            if (val.find(temp->val) != val.end()) {
                if (prev) {
                    prev->next = temp->next;
                    temp->next = NULL;
                    temp = prev->next;
                } else {
                    head = temp->next;
                    temp->next = NULL;
                    temp = head;
                }
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};