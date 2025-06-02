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
    private TreeNode first;
    private TreeNode middle;
    private TreeNode last;
    private TreeNode prev;

    private void swap(TreeNode a, TreeNode b){
        int temp = a.val;
        a.val = b.val;
        b.val = temp;
    }

    private void inorder(TreeNode root){
        if(root == null) return;

        inorder(root.left);

        if(prev != null && (root.val < prev.val)){

            if(first == null){
                first = prev;
                middle = root;
            }else{
                last = root;
            }
        }

        prev = root;

        inorder(root.right);
    }
    public void recoverTree(TreeNode root) {
        //first = middle = last = null;
        prev = new TreeNode(Integer.MIN_VALUE);
        inorder(root);

        if(first != null && last != null){
            swap(first,last);
        }else{
            swap(first,middle);
        }
    }
}