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
    int getMaxDiameter(TreeNode* root, int &maxDia) {
        if (root == NULL) return -1;
        int lh = getMaxDiameter(root->left, maxDia);
        int rh = getMaxDiameter(root->right, maxDia);
        maxDia = max(maxDia, 2+lh+rh);
        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        getMaxDiameter(root, maxDia);
        return maxDia;
    }
};