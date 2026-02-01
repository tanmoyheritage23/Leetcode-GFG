class Solution {
    public int finalElement(int[] nums) {
        int n = nums.length;
        return n == 1 ? nums[0] : Math.max(nums[0],nums[n-1]);
    }
}