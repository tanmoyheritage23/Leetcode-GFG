class Solution
{
    private:
        bool dfs(vector<vector < int>> &adj, int node, int destination, vector< int > &vis)
        {
            if (node == destination) return true;
            vis[node] = 1;
            for (auto &neighbour: adj[node])
            {
                if (!vis[neighbour] && dfs(adj, neighbour, destination, vis)) return true;
            }
           	// vis[node] = 0;
            return false;
        }
    public:
        bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
        {
            vector<vector < int>> adj(n);
            for (auto &edge: edges)
            {
                adj[edge[0]].push_back(edge[1]);
                adj[edge[1]].push_back(edge[0]);
            }

            vector<int> vis(n, 0);

            if (dfs(adj, source, destination, vis)) return true;

            return false;
        }
};