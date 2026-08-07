class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int count = 0;
        Queue<int[]>q = new LinkedList<>();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.offer(new int[]{i,j});
                }else if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        if(count == 0) return 0;

        int[] dx = {1,0,-1,0};
        int[] dy = {0,1,0,-1};

        int time = 0;

        while(!q.isEmpty()){
            int size = q.size();
            while(size-- > 0){
                int[] pos = q.poll();
                int row = pos[0], col = pos[1];
                for(int i = 0; i < 4; i++){
                    int nrow = row + dx[i];
                    int ncol = col + dy[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        grid[nrow][ncol] = 2;
                        count--;
                        q.offer(new int[]{nrow,ncol});
                    }
                }
            }
            time++;
        }

        return count == 0 ? time-1 : -1;


    }
}