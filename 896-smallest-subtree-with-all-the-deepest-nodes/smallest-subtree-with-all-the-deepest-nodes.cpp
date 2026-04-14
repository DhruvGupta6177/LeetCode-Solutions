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
    int maxdepth = 0;
    void finddepth(TreeNode* root, int depth){
        if(root == NULL){
            return;
        }

        maxdepth = max(maxdepth, depth);

        finddepth(root->left, depth+1);
        finddepth(root->right, depth+1);
    }

    TreeNode* findCA(TreeNode* root, int depth){
        if(root == NULL){
            return NULL;
        }

        if(depth == maxdepth){
            return root;
        }
        TreeNode* left = findCA(root->left, depth+1);
        TreeNode* right = findCA(root->right, depth+1);

        if(left && right){
            return root;
        }

        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        finddepth(root, 0);
        return findCA(root, 0);
    }
};