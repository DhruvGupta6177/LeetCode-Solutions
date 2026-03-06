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
    int height(TreeNode* root){
        if(!root) return -1;
        return 1 + max(height(root->left), height(root->right));
    }
    
    void fill(TreeNode* root, vector<vector<string>>& res, int r, int c, int h){
        if(!root) return;
        
        res[r][c] = to_string(root->val);
        
        int offset = pow(2, h - r - 1);
        
        if(root->left)
            fill(root->left, res, r + 1, c - offset, h);
        
        if(root->right)
            fill(root->right, res, r + 1, c + offset, h);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int rows = h + 1;
        int cols = pow(2, h + 1) - 1;
        
        vector<vector<string>> res(rows, vector<string>(cols, ""));
        
        fill(root, res, 0, (cols - 1) / 2, h);
        
        return res;
    }
};