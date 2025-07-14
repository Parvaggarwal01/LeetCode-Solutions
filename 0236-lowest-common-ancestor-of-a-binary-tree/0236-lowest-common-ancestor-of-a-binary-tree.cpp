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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL){
            return root;
        }
        TreeNode* leftnode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightnode = lowestCommonAncestor(root->right, p , q);
        if(leftnode==NULL && rightnode==NULL){
            return NULL;
        }
        if(leftnode && rightnode){
            return root;
        }
        if(leftnode == NULL){
            return rightnode;
        }else{
            return leftnode;
        }
    }
};