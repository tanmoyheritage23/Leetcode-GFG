class Solution
{
    public:
        string customSortString(string order, string s)
        {
            unordered_map<char, int> mp;
            vector<int> present(300,0);
            string ans = "";
            for (char ch: s) mp[ch]++;
            for (char ch: order)
            {
                if (mp[ch])
                {
                    while (mp[ch]--)
                    {
                        ans += ch;
                    }
                }
                present[ch] = 1;
            }

            string rest = "";
            for (char ch: s)
            {
                if (!present[ch]) rest += ch;
            }

            return ans + rest;
        }
};