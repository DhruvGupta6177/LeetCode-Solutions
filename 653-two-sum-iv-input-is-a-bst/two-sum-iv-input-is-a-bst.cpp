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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> seen;
        return dfs(root, k, seen);
    }

private:
    bool dfs(TreeNode* node, int k, unordered_set<int>& seen) {
        if (!node) return false;

        if (seen.count(k - node->val)) 
            return true;

        seen.insert(node->val);

        return dfs(node->left, k, seen) || dfs(node->right, k, seen);
    }
};
