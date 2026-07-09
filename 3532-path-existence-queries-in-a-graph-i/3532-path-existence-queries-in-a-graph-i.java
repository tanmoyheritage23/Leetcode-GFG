class Solution {
    public boolean[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[] group = new int[n];
        group[0] = 0;
        int currentGroup = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] - nums[i - 1] <= maxDiff) {
                group[i] = currentGroup;
            } else {
                group[i] = ++currentGroup;
            }
        }
        
        boolean[] ans = new boolean[queries.length];
        for (int i = 0; i < queries.length; i++) {
            int u = queries[i][0], v = queries[i][1];
            ans[i] = group[u] == group[v];
        }
        return ans;
    }
}