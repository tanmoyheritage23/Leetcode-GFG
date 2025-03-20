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
    private int memoizedDFS(TreeNode root, Map<TreeNode,Integer>dp){
        if(root==null) return 0;

        if(dp.containsKey(root)) return dp.get(root);

        int pick = root.val;

        if(root.left != null){
            pick += memoizedDFS(root.left.left,dp) + memoizedDFS(root.left.right,dp);
        }

        if(root.right != null){
            pick += memoizedDFS(root.right.left,dp) + memoizedDFS(root.right.right,dp);
        }

        int notPick = memoizedDFS(root.left,dp) + memoizedDFS(root.right,dp);

        int res = Math.max(pick,notPick);

        dp.put(root,res);

        return res;
    }
    public int rob(TreeNode root) {
        Map<TreeNode, Integer>dp = new HashMap<>();
        return memoizedDFS(root,dp);
    }
}