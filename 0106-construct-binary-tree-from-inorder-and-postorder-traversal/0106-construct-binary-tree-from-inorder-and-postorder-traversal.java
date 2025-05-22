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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if(postorder.length == 0 || inorder.length == 0) return null;

        TreeNode root = new TreeNode(postorder[postorder.length - 1]);

        int mid = - 1;
        for(int i = 0; i < inorder.length; i++){
            if(inorder[i] == postorder[postorder.length - 1]){
                mid = i;
                break;
            }

        }
        
        int[] leftPostorder = Arrays.copyOfRange(postorder,0,mid);
        int[] leftInorder = Arrays.copyOfRange(inorder,0,mid);

        root.left = buildTree(leftInorder,leftPostorder);

        int[] rightPostorder = Arrays.copyOfRange(postorder,mid,postorder.length-1);
        int[] rightInorder = Arrays.copyOfRange(inorder,mid+1,inorder.length);

        root.right = buildTree(rightInorder,rightPostorder);

        return root;

    }
}