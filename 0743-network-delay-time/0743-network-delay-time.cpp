class Solution
{
    private:
        vector<int> bfs(int src, unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist)
        {
            queue<pair<int, int>> q;
            dist[src] = 0;
            q.push({ 0,
                src });

            while (!q.empty())
            {
                auto it = q.front();
                q.pop();
                int d = it.first;
                int node = it.second;

                for (auto vec: adj[node])
                {
                    int adjNode = vec.first;
                    int edgeDist = vec.second;

                    if (d + edgeDist < dist[adjNode])
                    {
                        dist[adjNode] = d + edgeDist;
                        q.push({ dist[adjNode],
                            adjNode });
                    }
                }
            }

            return dist;
        }
    public:
        int networkDelayTime(vector<vector < int>> &times, int n, int k)
        {
            unordered_map<int, vector<pair<int, int>>> adj;
            for (int i = 0; i < times.size(); i++)
            {
                int u = times[i][0];
                int v = times[i][1];
                int time = times[i][2];

                adj[u].push_back({ v,
                    time });
            }

            vector<int> dist(n + 1, 1e9);
            bfs(k, adj, dist);

            int minTime = -1e9;
            for (int i = 1; i <= n; i++)
            {
                if (dist[i] == 1e9) return -1;
                if (minTime < dist[i])
                {
                    minTime = dist[i];
                }
            }

            return minTime;
        }
};