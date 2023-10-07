class Solution
{

    public:
        int mincostTickets(vector<int> &days, vector<int> &costs)
        {
            int n = days.size();
            vector<int> dp(days[n - 1] + costs[2], 0);

            for (int ind = n-1; ind >= 0; ind--)
            {
                int oneDayPassCost = costs[0];
                int sevenDayPassCost = costs[1];
                int thirtyDayPassCost = costs[2];

                int indAfter1DayPass = lower_bound(days.begin(), days.end(), days[ind] + 1) - days.begin();
                int take1DayPass = oneDayPassCost + dp[indAfter1DayPass];

                int indAfter7DayPass = lower_bound(days.begin(), days.end(), days[ind] + 7) - days.begin();
                int take7DayPass = sevenDayPassCost + dp[indAfter7DayPass];

                int indAfter30DayPass = lower_bound(days.begin(), days.end(), days[ind] + 30) - days.begin();
                int take30DayPass = thirtyDayPassCost + dp[indAfter30DayPass];

                int minCost = min(take1DayPass, min(take7DayPass, take30DayPass));

                dp[ind] = minCost;
            }

            return dp[0];
        }
};