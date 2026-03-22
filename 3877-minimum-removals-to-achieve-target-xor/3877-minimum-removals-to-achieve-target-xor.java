import java.util.*;

class Solution {
    public int minRemovals(int[] nums, int target) {
        int n = nums.length;
        int INF = (int) 1e9;

        int totalXor = 0;
        for (int num : nums) totalXor ^= num;

        int MAX = 100000; // same as your memo

        int[][] dp = new int[n + 1][MAX];

        // initialize all to INF
        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }

        // base case: i = -1 → dp[0]
        for (int x = 0; x < MAX; x++) {
            if (x == target) dp[0][x] = 0;
        }

        // build DP
        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];

            for (int x = 0; x < MAX; x++) {

                // not take
                int nt = dp[i - 1][x];

                // take
                int t = INF;
                int curr = x ^ num;
                if (curr < MAX && dp[i - 1][curr] != INF) {
                    t = 1 + dp[i - 1][curr];
                }

                dp[i][x] = Math.min(nt, t);
            }
        }

        int ans = dp[n][totalXor];
        return ans >= INF ? -1 : ans;
    }
}