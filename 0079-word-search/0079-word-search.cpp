class Solution
{
    private:
        bool foundWord(vector<vector < char>> &board, string word, int i, int j, int x, int n, int m)
        {
            if (x == word.size()) return true;
            if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '*' || board[i][j] != word[x]) return false;
            //if (word.size() == 1 && board[i][j] == word[x]) return true;
            board[i][j] = '*';
            bool temp = false;
            int dx[4] = { 0,
                1,
                -1,
                0
            };
            int dy[4] = { 1,
                0,
                0,
                -1
            };

            for (int ind = 0; ind < 4; ind++)
            {
                temp = temp || foundWord(board, word, i + dx[ind], j + dy[ind], x + 1, n, m);
            }
            board[i][j] = word[x];
            return temp;
        }
    public:
        bool exist(vector<vector < char>> &board, string word)
        {
            int n = board.size();
            int m = board[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (board[i][j] == word[0])
                    {
                        if (foundWord(board, word, i, j, 0, n, m)) return true;
                    }
                }
            }

            return false;
        }
};