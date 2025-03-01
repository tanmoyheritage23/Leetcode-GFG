class Solution {
    unordered_set<int> rowPosition;
    unordered_set<int> posDiagonal;
    unordered_set<int> negDiagonal;

private:
    void backtrack(int col, int n, vector<string>& board,
                   vector<vector<string>>& ans) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (rowPosition.find(row) != rowPosition.end() || posDiagonal.find(row - col) != posDiagonal.end() ||
                negDiagonal.find(row + col) != negDiagonal.end()) {
                continue;
            }
            rowPosition.insert(row);
            posDiagonal.insert(row - col);
            negDiagonal.insert(row + col);
            board[row][col] = 'Q';

            backtrack(col + 1, n, board, ans);

            rowPosition.erase(row);
            posDiagonal.erase(row - col);
            negDiagonal.erase(row + col);
            board[row][col] = '.';
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, ans);
        return ans;
    }
};