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
    int totaltilt = 0;

    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftsum = dfs(root->left);
        int rightsum = dfs(root->right);

        totaltilt += abs(leftsum - rightsum);

        return root->val + leftsum + rightsum;

    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return totaltilt;
    }
};