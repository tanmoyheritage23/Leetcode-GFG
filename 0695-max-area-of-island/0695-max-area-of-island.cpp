class Solution {
public:
    
    int dfs(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int m,int n,int &cs){
        vis[i][j]=true;
        
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        
        
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            
            if(nx>=0 and nx<m and ny>=0 and ny<n and grid[nx][ny]==1 and !vis[nx][ny]){
                cs++;
                dfs(grid,vis,nx,ny,m,n,cs);
                
            }
        }
        
        return cs;
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        
        int largest=0;
        
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int cs=1;                   // component size
                    int size=dfs(grid,vis,i,j,m,n,cs);
                    cout<<size<<endl;
                    if(size>largest) largest=size;
                    
                }
            }
        }
        
        return largest;
    }
};