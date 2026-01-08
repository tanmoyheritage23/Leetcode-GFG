class Solution {
    int[] A, B;
    Integer[][] memo;
    int n, m;
    final int NEG = Integer.MIN_VALUE / 2;

    public int maxDotProduct(int[] nums1, int[] nums2) {
        A = nums1;
        B = nums2;
        n = A.length;
        m = B.length;
        memo = new Integer[n][m];
        return dfs(0, 0);
    }

    private int dfs(int i, int j) {
        if (i == n || j == m) return NEG;

        if (memo[i][j] != null) return memo[i][j];

        int take = A[i] * B[j] + Math.max(0, dfs(i + 1, j + 1));
        int skipA = dfs(i + 1, j);
        int skipB = dfs(i, j + 1);

        return memo[i][j] = Math.max(take, Math.max(skipA, skipB));
    }
}