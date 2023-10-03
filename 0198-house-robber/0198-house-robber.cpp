class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n + 2, 0);

            for (int i = n - 1; i >= 0; i--)
            {
                int decidedToRob = nums[i] + dp[i + 2];
                int notDecidedToRob = 0 + dp[i + 1];
                int maxi = max(decidedToRob, notDecidedToRob);
                dp[i] = maxi;
            }

            return dp[0];
        }
};