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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode* temp = root;
        TreeNode* prev = NULL;
        TreeNode* right = NULL;
        while (temp) {
            if (prev) {
                TreeNode* currLeft = temp->left;
                TreeNode* currRight = temp->right;
                temp -> right = prev;
                temp -> left = right;
                right = currRight;
                prev = temp;
                temp = currLeft;
            } else {
                right = temp -> right;
                prev = temp;
                temp = temp -> left;
                prev -> left = NULL;
                prev -> right = NULL;
            }
        }
        return prev;
    }
};