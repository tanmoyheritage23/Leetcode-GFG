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
    
    private static class Result {
        int count = 0;
        int value = -1;
    }

    public int kthSmallest(TreeNode root, int k) {
        Result res = new Result();
        inorder(root, k, res);
        return res.value;
    }

    private void inorder(TreeNode node, int k, Result res) {
        if (node == null) return;

        inorder(node.left, k, res);
        
        res.count++;
        if (res.count == k) {
            res.value = node.val;
            return;
        }

        inorder(node.right, k, res);
    }
}