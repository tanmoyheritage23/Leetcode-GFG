class Solution {
    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        int maxArea = 0;

        int[][] cache = new int[n][m];

        for(int i = 0; i < n; i++){
            cache[i][0] = matrix[i][0] - '0';
            maxArea = Math.max(maxArea,cache[i][0]);
        }
        for(int j = 0; j < m; j++){
            cache[0][j] = matrix[0][j] - '0';
            maxArea = Math.max(maxArea,cache[0][j]);
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == '1'){
                   cache[i][j] = 1 + Math.min(cache[i-1][j], Math.min(cache[i-1][j-1],cache[i][j-1]));
                   
                }else cache[i][j] = 0;

                maxArea = Math.max(maxArea,cache[i][j]);
            }
        }

        return maxArea * maxArea;
    }
}