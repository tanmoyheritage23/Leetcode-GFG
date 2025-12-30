class Solution {

    private boolean isValid(int num) {
        return num >= 1 && num <= 9;
    }

    private int isMagicSquare(int[][] grid, int stRow, int stCol, int endRow, int endCol) {

        boolean[] seen = new boolean[10]; // to ensure 1..9 appear exactly once

        int[] rowSum = new int[3];
        int[] colSum = new int[3];
        int diag1 = 0, diag2 = 0;

        for (int i = stRow; i <= endRow; i++) {
            for (int j = stCol; j <= endCol; j++) {
                int num = grid[i][j];

                // check number validity
                if (!isValid(num) || seen[num]) return 0;
                seen[num] = true;

                int r = i - stRow;
                int c = j - stCol;

                rowSum[r] += num;
                colSum[c] += num;

                if (r == c) diag1 += num;
                if (r + c == 2) diag2 += num;
            }
        }

        // check diagonal sums
        if (diag1 != diag2) return 0;

        // check all row sums equal
        if (rowSum[0] != rowSum[1] || rowSum[1] != rowSum[2]) return 0;

        // check all column sums equal
        if (colSum[0] != colSum[1] || colSum[1] != colSum[2]) return 0;

        // check row sum == diagonal sum
        if (rowSum[0] != diag1) return 0;

        return 1;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        if (n < 3 || m < 3) return 0;

        int magicSquare = 0;

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                magicSquare += isMagicSquare(grid, i, j, i + 2, j + 2);
            }
        }

        return magicSquare;
    }
}