class Solution
{
    public:

        int minPathSum(vector<vector < int>> &grid)
        {
            int m = grid.size();
            int n = grid[0].size();
            vector<vector < int>> dp(m, vector<int> (n, 0));

            for (int i = m - 1; i >= 0; i--)
            {
                for (int j = n - 1; j >= 0; j--)

                {
                    if (i == m - 1 && j == n - 1) dp[i][j] = grid[m - 1][n - 1];
                    else
                    {

                        int right = grid[i][j];
                        if (j == n - 1) right += 1e7;
                        else right += dp[i][j + 1];

                        int down = grid[i][j];
                        if (i == m - 1) down += 1e7;
                        else down += dp[i + 1][j];

                        int mini = min(right, down);
                        dp[i][j] = mini;
                    }
                }
            }

            return dp[0][0];
        }
};