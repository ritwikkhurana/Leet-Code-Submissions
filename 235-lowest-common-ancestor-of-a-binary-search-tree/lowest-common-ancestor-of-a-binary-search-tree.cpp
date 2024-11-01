/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root -> val == p -> val || root -> val == q -> val) return root;
        TreeNode* left = (p->val < root->val || q->val < root->val) ? lowestCommonAncestor(root -> left, p, q) : NULL;
        TreeNode* right = (p->val > root->val || q->val > root->val) ? lowestCommonAncestor(root -> right, p, q) : NULL;
        if (left != NULL && right != NULL) return root;
        return left != NULL ? left : right;    }
};