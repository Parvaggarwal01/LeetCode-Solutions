/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    int count = 0;
public:
    void preorder(TreeNode* root,int max){
        if(root == NULL){
            return;
        }
        
        if(root->val >= max){
            count++;
            max = root->val;
        }
        preorder(root->left, max);
        preorder(root->right, max);
    }
    int goodNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        count = 0;
        preorder(root, root->val);
        return count;
    }
};