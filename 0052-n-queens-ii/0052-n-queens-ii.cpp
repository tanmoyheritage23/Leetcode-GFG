class Solution
{
    private:
    unordered_set<int> cols;	//for Columns
    unordered_set<int> negDiag;	//for negative diagnals R-C
    unordered_set<int> posDiag;	//for positive diagnals R+C
    void backtrack(int row, int n, vector<string> &board, int &count)
    {
       	// found a valid soln
        if (row == n)
        {
            count++;
            return;
        }

        for (int col = 0; col < n; col++)
        {
            if (cols.find(col) != cols.end() or negDiag.find(row - col) != negDiag.end() or posDiag.find(row + col) != posDiag.end())
            {
                continue;
            }

           	// placing queen
            cols.insert(col);
            negDiag.insert(row - col);
            posDiag.insert(row + col);
            board[row][col] = 'Q';

           	// Will try to place next queen in the next row
            backtrack(row + 1, n, board, count);

           	// after recursion call is over we will backtrack and will try to explore different positions

            cols.erase(col);
            negDiag.erase(row - col);
            posDiag.erase(row + col);
            board[row][col] = '.';
        }
    }
    public:
        int totalNQueens(int n)
        {
            vector<string> board(n, string(n, '.'));
            int count = 0;
            backtrack(0, n, board, count);
            return count;
        }
};