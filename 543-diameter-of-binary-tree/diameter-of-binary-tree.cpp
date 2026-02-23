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
    int ans = 0;
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int leftHT = height(root->left);
        int rightHT = height(root->right);
        ans = max(ans, leftHT + rightHT);

        return max(leftHT, rightHT) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
       height(root);

       return ans;
    }
};