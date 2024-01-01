class Solution
{ //link: https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/discuss/4480994/Greedy-oror-C%2B%2B-oror-Detailed-Explanation
    public:
        int maximumLength(string s)
        {
            int ans = 0;

            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                int count = 0;
                vector<int> counts;
                for (int i = 0; i < s.size(); i++)
                {
                    if (s[i] == ch) count++;
                    else
                    {
                        if (count != 0) counts.push_back(count);
                        count = 0;
                    }
                }
                if (count != 0) counts.push_back(count);
                sort(counts.begin(), counts.end());
                reverse(counts.begin(), counts.end());
                int cnt_size = counts.size();
                if (cnt_size == 0) continue;
                else if (cnt_size == 1)
                {
                    ans = max(ans, counts[0] - 2);
                }
                else if (cnt_size == 2)
                {
                    if (counts[0] == counts[1])
                    {
                        ans = max(ans, counts[0] - 1);
                    }
                    else
                    {
                        ans = max(ans, counts[1]);
                    }

                    ans = max(ans, counts[0] - 2);
                }
                else
                {
                    if (counts[0] == counts[1])
                    {

                        ans = max(ans, counts[0] - 1);
                    }
                    else
                    {
                        ans = max(ans, counts[1]);
                    }

                    ans = max(ans, counts[0] - 2);
                    ans = max(ans, counts[2]);
                }
            }

            if (ans != 0) return ans;
            return -1;
        }
};