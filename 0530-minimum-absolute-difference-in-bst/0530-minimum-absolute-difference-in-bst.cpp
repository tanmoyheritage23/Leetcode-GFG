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
    private:
    void dfs(TreeNode* root){
        /* Inorder traversal */
        if(root->left){
            dfs(root->left);
        }
        if(prev){
            minDiff = min(minDiff,root->val - prev->val);
        }
        prev = root;
        if(root->right){
            dfs(root->right);
        }
    }
    
public:
    int minDiff = INT_MAX; TreeNode* prev = NULL;
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minDiff;
    }
};