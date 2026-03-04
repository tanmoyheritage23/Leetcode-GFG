class Solution {
    public int numSpecial(int[][] mat) {

        int n = mat.length;
        int m = mat[0].length;

        int[] rowSum = new int[n];
        int[] colSum = new int[m];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1){
                    count++;
                }
            }
        }

        return count;
    }
}