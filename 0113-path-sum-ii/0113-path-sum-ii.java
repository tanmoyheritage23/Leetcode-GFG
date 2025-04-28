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
    private void rootToLeafSum(TreeNode root, int currSum, int targetSum, List<Integer>currList, List<List<Integer>>res){
        if(root == null){
            return;
        }

        currSum += root.val;
        currList.add(root.val);

        if(root.left == null && root.right == null && currSum == targetSum){
            res.add(new ArrayList<>(currList));
        }
        rootToLeafSum(root.left,currSum,targetSum,currList,res);
        rootToLeafSum(root.right,currSum,targetSum,currList,res);

        currList.remove(currList.size() - 1);
       
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>>res = new ArrayList<>();
        List<Integer>currList = new ArrayList<>();
        rootToLeafSum(root,0,targetSum,currList,res);
        return res;
        
        
    }
}