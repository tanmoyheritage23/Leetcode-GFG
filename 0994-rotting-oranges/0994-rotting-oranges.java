class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;

        int[][] vis = new int[n][m];
        Queue<int[]> q = new LinkedList<>();

        // Add all initially rotten oranges to queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.offer(new int[]{i, j, 0}); // row, col, time
                    vis[i][j] = 2;
                } else {
                    vis[i][j] = 0;
                }
            }
        }

        int[] drow = {-1, 0, 1, 0};
        int[] dcol = {0, 1, 0, -1};
        int tm = 0;

        while (!q.isEmpty()) {
            int[] front = q.poll();
            int r = front[0];
            int c = front[1];
            int t = front[2];
            tm = Math.max(tm, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                        && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    q.offer(new int[]{nrow, ncol, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }

        // Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return tm;
    }
}