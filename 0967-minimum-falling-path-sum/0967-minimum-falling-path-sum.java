class Solution {
    public int minFallingPathSum(int[][] matrix) {
        int n = matrix.length;
        Integer[][] memo = new Integer[n][n];
        int minSum = Integer.MAX_VALUE;

        for (int col = 0; col < n; col++) {
            minSum = Math.min(minSum, calculateMinSum(0, col, matrix, n, memo));
        }

        return minSum;
    }

    private int calculateMinSum(int row, int col, int[][] matrix, int n, Integer[][] memo) {
        if (col < 0 || col >= n) return Integer.MAX_VALUE; // Out of bounds
        if (row == n ) return 0; // Base case: last row

        if (memo[row][col] != null) return memo[row][col];

        int down = calculateMinSum(row + 1, col, matrix, n, memo);
        int downLeft = calculateMinSum(row + 1, col - 1, matrix, n, memo);
        int downRight = calculateMinSum(row + 1, col + 1, matrix, n, memo);

        memo[row][col] = matrix[row][col] + Math.min(down, Math.min(downLeft, downRight));
        System.out.println("memo[" + row + "][" + col + "] = " + memo[row][col]);
        return memo[row][col];
    }
}