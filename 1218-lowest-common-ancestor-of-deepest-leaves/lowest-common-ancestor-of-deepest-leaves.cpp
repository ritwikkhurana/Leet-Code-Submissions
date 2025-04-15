/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<TreeNode*, int> getlca(TreeNode* root) {
        if (root == NULL) return {NULL, 0};
        pair<TreeNode*, int> left = getlca(root->left);
        pair<TreeNode*, int> right = getlca(root->right);
        if (left.first == NULL && right.first == NULL) {
            return {root, 0};
        } else if (left.first == NULL || right.second > left.second) {
            return {right.first, right.second+1};
        } else if (right.first == NULL || left.second > right.second) {
            return {left.first, left.second+1};
        } else {
            return {root, left.second+1};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (root == NULL) return NULL;
        return getlca(root).first;
    }
};