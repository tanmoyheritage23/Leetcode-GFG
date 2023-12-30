class Solution
{
    public:
        long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector< int > &cost)
        {
            int n = original.size();
            long long res = 0;
            vector<vector < long long>> minCost(26, vector < long long > (26, INT_MAX));
            for (int i = 0; i < n; i++)
            {
                int s = original[i] - 'a', t = changed[i] - 'a';
                minCost[s][t] = min(minCost[s][t], (long long)cost[i]);
            }

            for (int k = 0; k < 26; k++)
            {
                for (int i = 0; i < 26; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }

            for (int i = 0; i < source.size(); i++)
            {
                if (source[i] == target[i]) continue;
                else
                {
                    int s = source[i] - 'a', t = target[i] - 'a';
                    if (minCost[s][t] >= INT_MAX) return -1;
                    res += minCost[s][t];
                }
            }

            return res;
        }
};