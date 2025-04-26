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
    private long prev = Long.MIN_VALUE;
    private boolean assign(long n){
        boolean returnVal = prev < n;
        prev = n;
        return returnVal;
    }
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        return isValidBST(root.left) && assign(root.val) && isValidBST(root.right);
        
    }
}