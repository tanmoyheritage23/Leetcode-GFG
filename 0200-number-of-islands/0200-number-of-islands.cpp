class Solution
{
    private:
        void dfs(vector<vector < char>> &grid, int row, int col, int n, int m, int dx[], int dy[], vector<vector < int>> &vis)
        {
            vis[row][col] = 1;
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + dx[i];
                int newCol = col + dy[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == '1' && !vis[newRow][newCol])
                {
                    dfs(grid, newRow, newCol, n, m, dx, dy, vis);
                }
            }
        }
    public:
        int numIslands(vector<vector < char>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();

            int dx[4] = { 1,
                0,
                -1,
                0
            };
            int dy[4] = { 0,
                1,
                0,
                -1
            };

            int count = 0;
            vector<vector < int>> vis(n, vector<int> (m, 0));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == '1' && !vis[i][j])
                    {
                        count++;
                        dfs(grid, i, j, n, m, dx, dy, vis);
                    }
                }
            }

            return count;
        }
};