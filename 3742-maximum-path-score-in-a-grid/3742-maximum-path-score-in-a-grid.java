class Solution {
    public int maxPathScore(int[][] grid, int k) {
        int n = grid.length;
        int m = grid[0].length;

        int[][][] dp = new int[n][m][k + 1];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                Arrays.fill(dp[i][j], -1);
            }
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                for(int cost = k; cost >= 0; cost--){
                    int newCost = cost + (grid[i][j] == 0 ? 0 : 1);

                    if(newCost > k) continue;

                    if(i == n - 1 && j == m - 1) {
                        dp[i][j][cost] = grid[i][j];
                        continue;
                    }

                    int right = -1;
                    int down = -1;

                    if(i + 1 < n) down = dp[i + 1][j][newCost];
                    if(j + 1 < m) right = dp[i][j + 1][newCost];

                    int bestNext = Math.max(down, right);

                    if(bestNext != -1 ) dp[i][j][cost] = bestNext + grid[i][j];
                }
            }
        }

        return dp[0][0][0];
    }
}