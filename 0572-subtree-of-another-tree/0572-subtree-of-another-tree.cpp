class Solution {
public:
    bool isSameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;                 
        if (!root || !subRoot) return false;                 
        if (root->val != subRoot->val) return false;         

        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;                    
        if (isSameTree(root, subRoot)) return true; 
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
