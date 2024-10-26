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
    void bfs(TreeNode *root, unordered_map<int, pair<int,int>> &ourmap) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        ourmap[root->val] = {0,-1};
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            if (node -> left) {
                q.push({node->left, level+1});
                ourmap[node->left->val] = {level+1, -1};
            }
            if (node->right) {
                q.push({node->right, level+1});
                ourmap[node->right->val] = {level+1, -1};
            }
        }
    }

    int dfs(TreeNode *root, unordered_map<int, pair<int,int>> &ourmap, unordered_map<int, set<pair<int,int>, greater<pair<int,int>>>> &levelMap) {
        if (root == NULL) return 0;
        int left = dfs(root->left, ourmap, levelMap);
        int right = dfs(root->right, ourmap, levelMap);
        int maxSubHeight = max(left, right);
        ourmap[root->val].second = maxSubHeight;
        int level = ourmap[root->val].first;
        levelMap[level].insert({maxSubHeight, root->val});
        return 1 + maxSubHeight;
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<int, pair<int,int>> ourmap;
        unordered_map<int, set<pair<int,int>, greater<pair<int,int>>>> levelMap; 
        bfs(root, ourmap);
        dfs(root, ourmap, levelMap);
        vector<int> output;
        for (int i: queries) {
            int level = ourmap[i].first;
            if (levelMap[level].size() > 1) {
                int maxSubHeight;
                pair<int,int> firstPair = *levelMap[level].begin();
                pair<int,int> secondPair = *(next(levelMap[level].begin(),1));
                if (firstPair.second != i) {
                    maxSubHeight = firstPair.first;
                } else {
                    maxSubHeight = secondPair.first;
                }
                output.push_back(level + maxSubHeight);
            } else {
                output.push_back(level-1);
            }
        }
        return output;
    }
};