class Solution {

    int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int R, C;

    public int latestDayToCross(int row, int col, int[][] cells) {
        R = row;
        C = col;

        boolean[][] water = new boolean[R][C];

        for (int day = 0; day < cells.length; day++) {

            // Flood today's cell
            int r = cells[day][0] - 1;
            int c = cells[day][1] - 1;
            water[r][c] = true;

            boolean[][] visited = new boolean[R][C];
            boolean canCross = false;

            // Try DFS from every top row land cell
            for (int j = 0; j < C; j++) {
                if (!water[0][j] && !visited[0][j]) {
                    if (dfs(0, j, water, visited)) {
                        canCross = true;
                        break;
                    }
                }
            }

            // If crossing not possible → previous day was last valid
            if (!canCross) return day;
        }

        return 0;
    }

    private boolean dfs(int r, int c, boolean[][] water, boolean[][] visited) {
        if (r == R - 1) return true; // reached bottom

        visited[r][c] = true;

        for (int[] d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                !water[nr][nc] && !visited[nr][nc]) {

                if (dfs(nr, nc, water, visited))
                    return true;
            }
        }
        return false;
    }
}