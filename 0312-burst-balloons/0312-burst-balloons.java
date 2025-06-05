class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] newNums = new int[n + 2];
        newNums[0] = 1;
        newNums[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            newNums[i + 1] = nums[i];
        }

        int[][] dp = new int[n + 2][n + 2];

        return burst(newNums, dp, 0, n + 1);
    }

    private int burst(int[] nums, int[][] dp, int left, int right) {
        if (left + 1 == right) return 0; // no balloon to burst between

        if (dp[left][right] > 0) return dp[left][right];

        int maxCoins = 0;
        for (int i = left + 1; i < right; i++) {
            int coins = nums[left] * nums[i] * nums[right];
            coins += burst(nums, dp, left, i);
            coins += burst(nums, dp, i, right);
            maxCoins = Math.max(maxCoins, coins);
        }

        dp[left][right] = maxCoins;
        return maxCoins;
    }
}