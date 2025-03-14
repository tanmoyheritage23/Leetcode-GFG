class Solution {
    public int[] findDiagonalOrder(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int row = 0,col = 0;
        int output[] = new int[n*m];
        for(int pos = 0; pos < n*m; pos++){
            output[pos] = mat[row][col];
            if((row + col) % 2 == 0){
                if(col == m-1) row++;
                else if(row == 0) col++;
                else {row--;col++;}
            }else{
                if(row == n-1) col++;
                else if(col == 0) row++;
                else {row++;col--;}
            }
        }

        return output;
    }
}