class Solution
{
    public:
        int maxFrequencyElements(vector<int> &nums)
        {
            unordered_map<int, int> mp;
            int maxFreq= 0; int count = 0;
            for (int it: nums)
            {
                mp[it]++;
                maxFreq = max(maxFreq, mp[it]);
            }
            for (auto &[key, val]: mp)
            {
                if (mp[key] == maxFreq) count++;
            }

            return count * maxFreq;
        }
};