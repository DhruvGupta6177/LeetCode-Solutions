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
    unordered_map<string,int> mp;
    vector<TreeNode*> result;

    string dfs(TreeNode* root)
    {
        if(root == NULL)
            return "#";

        string left = dfs(root->left);
        string right = dfs(root->right);

        string subtree = to_string(root->val) + "," + left + "," + right;

        mp[subtree]++;

        if(mp[subtree] == 2)
            result.push_back(root);

        return subtree;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return result;
    }
};