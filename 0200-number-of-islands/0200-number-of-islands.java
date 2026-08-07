class Solution {
    public int numIslands(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};
        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(i,j,grid,n,m,dx,dy,vis);
                    count++;
                }
                
            }
        }

        return count;
    }

    private void dfs(int row, int col, char[][]grid, int n, int m, int[] dx, int[] dy, boolean[][] vis){
        vis[row][col] = true;

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,n,m,dx,dy,vis);
            }
        }
    }
}