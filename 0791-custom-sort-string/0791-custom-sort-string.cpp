class Solution
{
    public:
        string customSortString(string order, string s)
        {
            unordered_map<char, int> mp;
            string ans = "";
            for (char ch: s) mp[ch]++;
            for (char ch: order)
            {

                while (mp[ch]--)
                {
                    ans += ch;
                }
            }

            for (auto &[ch, count]: mp)
            {
                while (count-- > 0) ans += ch;
            }

            return ans;
        }
};