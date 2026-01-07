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
    long long maxProd = 0;
    long long total = 0;
    const int MOD = 1e9 + 7;
    
    long long getTotalSum(TreeNode* root){
        if(!root){
            return 0;
        }
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    long long dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subSum = root->val + left + right;

        maxProd = max(maxProd, subSum * (total - subSum));
        return subSum;
    }

    int maxProduct(TreeNode* root) {
        total = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};