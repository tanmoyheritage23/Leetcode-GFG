class Solution
{ // For explanation watch striver dp-50 && read this discussion https://leetcode.com/problems/minimum-cost-to-cut-a-stick/discuss/1222820/c%2B%2B-DP-top-down-approach-(idea-similar-to-MCM)
    public:
        int helper(int i, int j, vector<int> &cuts, vector<vector< int>> &dp)
        {
            if (i > j) return 0;
            if (dp[i][j] != -1) return dp[i][j];
            int mini = INT_MAX;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + helper(i, ind - 1, cuts, dp) + helper(ind + 1, j, cuts, dp);
                mini = min(mini, cost);
            }
            return dp[i][j] = mini;
        }
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector < int>> dp(c + 1, vector<int> (c + 1, -1));
        return helper(1, c, cuts, dp);
    }
};