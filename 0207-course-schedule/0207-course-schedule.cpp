class Solution
{
    private:
        bool dfsCycle(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis)
        {
            vis[node] = 1;
            pathVis[node] = 1;

            for (auto it: adj[node])
            {
                if (!vis[it])
                {
                    if(dfsCycle(it, adj, vis, pathVis)) return true;
                }
                else if(pathVis[it]) return true;
            }

            pathVis[node] = 0;
            return false;
        }
    public:
        bool canFinish(int numCourses, vector<vector < int>> &prerequisites)
        {
            vector<int> adj[numCourses];
            for (int i = 0; i < prerequisites.size(); i++)
            {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            }

            vector<int>vis(numCourses,0);
            vector<int>pathVis(numCourses,0);
            for (int i = 0; i < numCourses; i++)
            {
                if (!vis[i])
                {
                    if (dfsCycle(i, adj, vis, pathVis)==true) return false;
                }
            }

            return true;
        }
};