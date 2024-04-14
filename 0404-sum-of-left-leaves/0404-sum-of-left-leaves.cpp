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
    void AddLeftLeaves(TreeNode* root, int &sum) {
        if (!root) return;
        if (root->left && !root->left->left && !root->left->right) {
            sum += root->left->val;
        }
        AddLeftLeaves(root->left, sum); // Pass sum by reference
        AddLeftLeaves(root->right, sum); // Pass sum by reference
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        AddLeftLeaves(root, sum); // Pass sum by reference
        return sum;
    }
};
