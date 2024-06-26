class Solution
{
       public:
        vector<int> findMinHeightTrees(int n, vector<vector < int>> &edges)
        {
            vector<vector < int>> adj(n);
            vector<int>indegree(n,0),ans;
            for (auto edge: edges)
            {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
                indegree[edge[0]]++;
                indegree[edge[1]]++;
            }
            
            queue<int>q;
            for(int i = 0; i < n; i++){
                if(indegree[i]==1) q.push(i), indegree[i]--;
            }
            
            
            while(!q.empty()){
                int s = q.size();
                ans.clear();
                for(int i = 0;i < s; i++){
                    int curr = q.front();
                    q.pop();
                    ans.push_back(curr);
                    for(auto child: adj[curr]){
                        indegree[child]--;
                        if(indegree[child]==1) q.push(child);
                    }
                }
            }

            if(n==1) return {0};
            return ans;
        }
};