class Solution {
    public int countNegatives(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int row = 0, col = m - 1;
        int negNumbers = 0;

        while(row < n && col >= 0){
            if(grid[row][col] < 0){
                negNumbers += n - row;
                col--;
            }else{
                row++;
            }
        }

        return negNumbers;
    }
}