class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    for (int i = 0; i < n; i++) {
        vector<int> diag;
        for (int r = i, c = 0; r < n && c < n; r++, c++)
            diag.push_back(grid[r][c]);
        sort(diag.begin(), diag.end(), greater<int>());
        for (int r = i, c = 0, k = 0; r < n && c < n; r++, c++, k++)
            grid[r][c] = diag[k];
    }
    for (int j = 1; j < n; j++) {
        vector<int> diag;
        for (int r = 0, c = j; r < n && c < n; r++, c++)
            diag.push_back(grid[r][c]);
        sort(diag.begin(), diag.end());
        for (int r = 0, c = j, k = 0; r < n && c < n; r++, c++, k++)
            grid[r][c] = diag[k];
    }
    return grid;
    }
};