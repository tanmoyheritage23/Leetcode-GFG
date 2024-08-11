class Solution
{
    private:
        void dfs(int row, int col, vector<vector < int>> &vis, vector< vector< int>> &grid, int n, int m)
        {
            vis[row][col] = 2;

            int drow[4] = { 1,
                0,
                0,
                -1
            };
            int dcol[4] = { 0,
                1,
                -1,
                0
            };

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
                {
                    dfs(nrow, ncol, vis, grid, n, m);
                }
            }
        }
    int exploreIsland(vector<vector < int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector < int>> vis(n, vector<int> (m, 0));
        int island = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    dfs(i, j, vis, grid, n, m);
                    island++;
                }
            }
        }
        return island;
    }
    public:
        int minDays(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();

            int island = exploreIsland(grid);

            if (island != 1) return 0;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if(grid[i][j]==0) continue;
                    
                    grid[i][j]=0;
                    
                    island = exploreIsland(grid);

                    if (island != 1) return 1;

                    grid[i][j] = 1;
                }
            }

            return 2;
        }
};