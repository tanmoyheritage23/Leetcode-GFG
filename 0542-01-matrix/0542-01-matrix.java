class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        Queue<int[]>q = new LinkedList<>();
        int[][] result = new int[n][m];
        int[][] directions = {{1,0},{0,1},{-1,0},{0,-1}};

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
              if(mat[i][j] == 0){
                q.offer(new int[]{i,j});
              }else{
                result[i][j] = -1;
              }
            }
        }

        while(!q.isEmpty()){
            int[] temp = q.poll();
            int row = temp[0];
            int col = temp[1];

            for(int[] dir: directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && result[newRow][newCol] == -1){
                    result[newRow][newCol] = 1 + result[row][col];
                    q.offer(new int[]{newRow,newCol});
                }
            }
        }

        return result;
    }
}