class Solution
{
    public:
        int islandPerimeter(vector<vector < int>> &grid)
        {

            int n = grid.size();
            int m = grid[0].size();

            int perimeter = 0;

            int dx[4] = { 0,
                1,
                0,
                -1
            };
            int dy[4] = { 1,
                0,
                -1,
                0
            };

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        perimeter += 4;
                        for (int p = 0; p < 4; p++)
                        {
                            int new_i = i + dx[p];
                            int new_j = j + dy[p];
                            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1)
                            {
                                perimeter -= 1;
                            }
                        }
                    }
                }
            }

            return perimeter;
        }
};