class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        if(grid[0][0] == 1) return -1;
        dist[0][0] = 1;
        q.push({1,{0,0}});

        int drow[] = {-1,-1,0,1,1,1,0,-1};
        int dcol[] = {0,1,1,1,0,-1,-1,-1};

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 8; i++){
                int newRow = row + drow[i];
                int newCol = col + dcol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < n && grid[newRow][newCol] == 0 && dis + 1 < dist[newRow][newCol]){
                    dist[newRow][newCol] = dis + 1;
                    q.push({dist[newRow][newCol],{newRow,newCol}});
                }
            }
        }
        if(dist[n-1][n-1] != 1e9 && grid[n-1][n-1] != 1) return dist[n-1][n-1];
        return -1;
    }
};