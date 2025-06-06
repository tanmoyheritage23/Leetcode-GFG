/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        solve(root, 0, res);
        return res;
    }

    private void solve(TreeNode root, int level, List<Integer> res) {
        if (root == null) return;

        // If we are visiting this level for the first time, add the node
        if (res.size() == level) {
            res.add(root.val);
        }

        // Visit right subtree first, then left
        solve(root.right, level + 1, res);
        solve(root.left, level + 1, res);
    }
}