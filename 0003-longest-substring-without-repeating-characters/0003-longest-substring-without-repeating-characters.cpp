class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int n = s.length();
            int st = 0, end = 0, ans = 0;
            int freq[128]={};

            while (end < n)
            {
                freq[s[end]]++;
                while (freq[s[end]] > 1)
                {
                    freq[s[st]]--;
                    st++;
                }

                ans = max(ans, end - st + 1);
                end++;
            }

            return ans;
        }
};