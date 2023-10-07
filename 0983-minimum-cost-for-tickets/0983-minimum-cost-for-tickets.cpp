class Solution
{

    public:
        int mincostTickets(vector<int> &days, vector<int> &costs)
        {
            queue<pair<int, int>> week, month;	// day,cost
            int ans = 0;

            for (int day: days)
            {
                while (!week.empty() && week.front().first + 7 <= day) week.pop();
                while (!month.empty() && month.front().first + 30 <= day) month.pop();

                week.push(make_pair(day, ans + costs[1]));
                month.push(make_pair(day, ans + costs[2]));

                ans = min(ans + costs[0], min(week.front().second, month.front().second));
            }

            return ans;
        }
};