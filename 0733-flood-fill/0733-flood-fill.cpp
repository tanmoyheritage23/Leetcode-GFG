class Solution
{
    public:
       	//  in this case we don't need a separate visited structure: changing the color(2) guarantees we will not go to the same cell again.
        vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
        {
            int n = image.size();
            int m = image[0].size();

            queue<pair<int, int>> q;

            q.push({ sr,
                sc });

            int startColor = image[sr][sc];

            int dx[] = { -1,
                0,
                1,
                0
            };
            int dy[] = { 0,
                1,
                0,
                -1
            };

            while (!q.empty())
            {
                int row = q.front().first;
                int col = q.front().second;
                image[row][col] = color;
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int newRow = row + dx[i];
                    int newCol = col + dy[i];

                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && image[newRow][newCol] != color && image[newRow][newCol] == startColor)
                    {
                        q.push({ newRow,
                            newCol });
                    }
                }
            }

            return image;
        }
};