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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == NULL) return -1;

        long left = -1, right = -1;

        if(root->left){
            if(root->left->val == root->val)
                left = findSecondMinimumValue(root->left);
            else
                left = root->left->val;
        }

        if(root->right){
            if(root->right->val == root->val)
                right = findSecondMinimumValue(root->right);
            else
                right = root->right->val;
        }

        if(left == -1) return right;
        if(right == -1) return left;

        return min(left, right);
    }
};