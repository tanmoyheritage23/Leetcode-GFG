class Solution
{
    public:
        int minFlips(vector<vector < int>> &grid)
        {
            int n = grid.size();
            int m = grid[0].size();

            int ans = 0;
           	// for a particular {i,j} i am checking all it's palindromic dependent
           	// places. I need to flip min(countOf0,countOf1). And the most interesting part is I am making all the four places either 0 or 1 so divisibilty by 4 is maintained throughout the traversing 
            for (int i = 0; i < n / 2; i++)
            {
                for (int j = 0; j < m / 2; j++)
                {
                    int x = grid[i][j];
                    x += grid[i][m - j - 1];
                    x += grid[n - i - 1][j];
                    x += grid[n - i - 1][m - j - 1];

                    ans += min(x, 4 - x);
                }
            }

           	//But the problem occurs if the n = odd or m = odd or both n and m are odds. Then we need to take care of middle row and middle cols

            int cnt = 0;	// flip count in the middle row and col
            int onePair = 0;	// count of pair of 1's in the middle row and col

            if (n % 2 == 1)
            {
                for (int j = 0; j < m / 2; j++)
                {
                    if (grid[n / 2][j] != grid[n / 2][m - j - 1])
                    {
                        ans++;
                        cnt++;
                    }
                    if (grid[n / 2][j] == grid[n / 2][m - j - 1] && (grid[n / 2][j] == 1))
                    {
                        onePair++;
                    }
                }
            }

            if (m % 2 == 1)
            {
                for (int j = 0; j < n / 2; j++)
                {
                    if (grid[j][m / 2] != grid[n - j - 1][m / 2])
                    {
                        ans++;
                        cnt++;
                    }
                    if (grid[j][m / 2] == grid[n - j - 1][m / 2] && (grid[j][m / 2] == 1))
                    {
                        onePair++;
                    }
                }
            }

           	// If onepair count is odd and all the places in the middle row and col are already palindromic in that case we need minimum 2 more operations to make all the 1's in grid divisble by 4.
            if ((onePair % 2 == 1) && (cnt == 0)) ans += 2;

           	// If both n and m are odd and the middle element of grid is also 1 
           	// then we need minimum 1 more operation to make all the 1's divisible by 4

            if ((n % 2 == 1 && m % 2 == 1) && (grid[n / 2][m / 2] == 1)) ans++;

            return ans;
        }
};