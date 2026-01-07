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
    static final int MOD = 1000000007;
    long ans = 0, total = 0;

    private long calculateMaxProduct(TreeNode root) {
        if (root == null) return 0;

        long s = root.val
               + calculateMaxProduct(root.left)
               + calculateMaxProduct(root.right);

        ans = Math.max(ans, (total - s) * s);
        return s;
    }

    private long dfs(TreeNode root) {
        if (root == null) return 0;
        return root.val + dfs(root.left) + dfs(root.right);
    }

    public int maxProduct(TreeNode root) {
        total = dfs(root);
        calculateMaxProduct(root);
        return (int) (ans % MOD);
    }
}