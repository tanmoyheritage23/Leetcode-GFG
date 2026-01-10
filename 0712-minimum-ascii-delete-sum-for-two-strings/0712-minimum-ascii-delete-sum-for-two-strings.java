class Solution {

    private int helper(int i, int j, int n, int m, String s1, String s2, int[][] dp) {
        if (i == n) {
            int sum = 0;
            while (j < m) {
                sum += s2.charAt(j++);
            }
            return sum;
        }

        if (j == m) {
            int sum = 0;
            while (i < n) {
                sum += s1.charAt(i++);
            }
            return sum;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = Integer.MAX_VALUE;
        if (s1.charAt(i) == s2.charAt(j)) {
            ans = helper(i + 1, j + 1, n, m, s1, s2, dp);
        } else {
            int skipS1 = s1.charAt(i) + helper(i + 1, j, n, m, s1, s2, dp);
            int skipS2 = s2.charAt(j) + helper(i, j + 1, n, m, s1, s2, dp);
            ans = Math.min(skipS1, skipS2);
        }

        return dp[i][j] = ans;
    }

    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++)
            Arrays.fill(dp[i], -1);

        return helper(0, 0, n, m, s1, s2, dp);
    }
}