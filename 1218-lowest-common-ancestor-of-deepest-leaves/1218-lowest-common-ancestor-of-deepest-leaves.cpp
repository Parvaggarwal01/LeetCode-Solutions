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
        if(root == NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        return 1 + max(left, right);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h = height(root);
        int lh = height(root->left);
        int rh = height(root->right);
        if(rh == lh){
            return root;
        }
        else if(rh > lh){
            return lcaDeepestLeaves(root->right);
        }
        else{
            return lcaDeepestLeaves(root->left);
        }
        
    }
};