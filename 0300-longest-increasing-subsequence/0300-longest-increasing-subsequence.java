class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];

        int length = 0;

        for (int i = 1; i <= n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                if (nums[i-1] > nums[j-1]) {
                    dp[i] = Math.max(dp[i], 1 + dp[j]);
                }
            }
            length = Math.max(length, dp[i]);
        }

        return length;
    }
}