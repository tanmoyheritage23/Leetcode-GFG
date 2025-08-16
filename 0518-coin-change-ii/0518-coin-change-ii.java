class Solution {
    public int change(int amount, int[] coins) {
        int N = coins.length;
        long[][] dp = new long[N][amount + 1];

        // Initializing base condition
        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = 1;
            /* Else condition is automatically fulfilled,
            as dp array is initialized to zero */
        }

        for (int ind = 1; ind < N; ind++) {
            for (int target = 0; target <= amount; target++) {
                int notTaken = (int)dp[ind - 1][target];

                int taken = 0;
                if (coins[ind] <= target)
                    taken = (int)dp[ind][target - coins[ind]];

                dp[ind][target] = (notTaken + taken);
            }
        }
        // Return the result
        return (int)dp[N - 1][amount];
    }
}