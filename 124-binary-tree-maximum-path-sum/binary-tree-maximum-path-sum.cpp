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
    int pathSum(TreeNode *root, int &sum) {
        if (root == NULL) return 0;

        int lsum = pathSum(root -> left, sum);
        int rsum = pathSum(root -> right, sum);

        sum = max(sum, max(root->val, max(root->val+lsum+rsum, root->val+max(lsum,rsum))));
        return max(root->val, root->val+max(lsum,rsum));
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        pathSum(root, sum);
        return sum;
    }
};