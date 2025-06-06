/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    private:
        void solve(TreeNode *root, int level, vector<int> &res)
        {
            if (!root) return;
           	// At each level we see only the rightmost node of that respective level. if no right node exists then go for the left node. At each level we put only one the one element into the vector res
            if (res.size() == level) res.push_back(root->val);
            solve(root->right, level + 1, res);
            solve(root->left, level + 1, res);
        }
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            if (!root) return {};
            vector<int> res;
            solve(root, 0, res);
            return res;
        }
};