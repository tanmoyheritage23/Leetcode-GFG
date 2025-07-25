/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        int solve(TreeNode *root, int curr)
        {   
            if(!root) return 0;
            curr = curr*10 + root->val;
            if(!root->left && !root->right) return curr;
            else{
            int l = solve(root->left,curr);
            int r = solve(root->right,curr);
            return l+r;
            }
        }
    public:
        int sumNumbers(TreeNode *root)
        {
            return solve(root,0);
        }
};