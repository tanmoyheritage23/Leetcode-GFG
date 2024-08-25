class Solution
{
    private:
        string makeDigit(int num, int digits)
        {
            string s = to_string(num);
            int n = s.size();

            for (int i = 0; i < digits - n; i++)
            {
                s = "0" + s;
            }

            return s;
        }
    unordered_set<string> possibleCombinationAfterSwaps(int num, int digits)
    {
        unordered_set<string> poss;
        string s = makeDigit(num, digits);
       	// 0th swap
        poss.insert(s);
        for (int i = 0; i < digits; i++)
        {
            for (int j = i + 1; j < digits; j++)
            {
                if (s[i] != s[j])
                {
                   	// 1st swap
                    swap(s[i], s[j]);
                    poss.insert(s);
                }

                for (int i1 = 0; i1 < digits; i1++)
                {
                    for (int j1 = i1 + 1; j1 < digits; j1++)
                    {
                       	// 2nd swap
                        if (s[i1] != s[j1])
                        {
                            swap(s[i1], s[j1]);
                            poss.insert(s);
                           	// backtrack
                            swap(s[j1], s[i1]);
                        }
                    }
                }

               	// backtrack
                swap(s[j], s[i]);
            }
        }

        return poss;
    }
    public:
        int countPairs(vector<int> &nums)
        {
            int n = nums.size();
            int digits = to_string(*max_element(nums.begin(), nums.end())).size();
            unordered_map<string, int> mp;
            int ans = 0;
            for (int i = 0; i < n; i++)
            {
                for (const string &s: possibleCombinationAfterSwaps(nums[i], digits))
                {
                    if (mp.count(s))
                    {
                        ans += mp[s];
                    }
                }

                mp[makeDigit(nums[i], digits)]++;
            }

            return ans;
        }
};