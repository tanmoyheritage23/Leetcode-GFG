class Solution {
public:
    int f(int ind, int amount, vector<int>& coins, vector<vector<int>>& dp) {
        // Base case: only one coin type
        if (ind == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            else
                return 1e9; // large number to denote impossible
        }

        if (dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = f(ind - 1, amount, coins, dp);
        int take = INT_MAX;
        if (coins[ind] <= amount)
            take = 1 + f(ind, amount - coins[ind], coins, dp);

        return dp[ind][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};