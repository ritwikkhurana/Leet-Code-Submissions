/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head;
        do {
            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow && fast != NULL && fast->next != NULL);
        if (fast == slow) return true;
        return false;
    }
};