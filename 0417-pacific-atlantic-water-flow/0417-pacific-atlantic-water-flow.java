class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        int numRows = heights.length;
        int numCols = heights[0].length;

        boolean[][] pacificReachable = new boolean[numRows][numCols];
        boolean[][] atlanticReachable = new boolean[numRows][numCols];

        for (int i = 0; i < numRows; i++) {
            dfs(heights, pacificReachable, i, 0);
            dfs(heights, atlanticReachable, i, numCols - 1);
        }

        for (int j = 0; j < numCols; j++) {
            dfs(heights, pacificReachable, 0, j);
            dfs(heights, atlanticReachable, numRows - 1, j);
        }

        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    result.add(Arrays.asList(i, j));
                }
            }
        }

        return result;
    }

    private void dfs(int[][] heights, boolean[][] reachable, int r, int c) {
        int numRows = heights.length;
        int numCols = heights[0].length;
        int[][] dirs = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

        reachable[r][c] = true;

        for (int[] dir : dirs) {
            int newRow = r + dir[0], newCol = c + dir[1];
            if (newRow < 0 || newRow >= numRows || newCol < 0 || newCol >= numCols)
                continue;
            if (reachable[newRow][newCol])
                continue;
            if (heights[newRow][newCol] < heights[r][c])
                continue;

            dfs(heights, reachable, newRow, newCol);
        }
    }
};