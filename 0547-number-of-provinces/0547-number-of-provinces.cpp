class Solution {
public:
void bfs(int node, unordered_map<int,vector<int>>&adj, vector<int>&vis){
     queue<int>q;
     q.push(node);
     vis[node] = 1;

     while(!q.empty()){
         int node = q.front();
         q.pop();
         for(int &j :adj[node]){
             if(!vis[j]){
                 q.push(j);
                 vis[j] = 1;
             }
         }
     }
}
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>>adj;

        int n = isConnected.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i + 1  != j + 1  && isConnected[i][j] == 1){
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        vector<int>vis(n+1,0);
        int cnt = 0;

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                bfs(i,adj,vis);
                cnt++;
            }
        }

        return cnt;
    }
};