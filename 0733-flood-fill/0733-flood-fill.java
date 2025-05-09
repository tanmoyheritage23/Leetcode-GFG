class Solution {
    private void dfs(int row, int col, int[][] image, int color, int initialColor, int[] drow, int[] dcol){
        image[row][col] = color;
        int n = image.length;
        int m = image[0].length;
        for(int i = 0; i < 4; i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && image[nrow][ncol] != color){
                dfs(nrow,ncol,image,color,initialColor,drow,dcol);
            }
        }
    }
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        int[] drow = {1,-1,0,0};
        int[] dcol = {0,0,1,-1};
        dfs(sr,sc,image,color,initialColor,drow,dcol);
        return image;
    }
}