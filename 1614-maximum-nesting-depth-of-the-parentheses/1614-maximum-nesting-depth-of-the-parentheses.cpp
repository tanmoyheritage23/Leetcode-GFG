class Solution
{
    public:
        int maxDepth(string s)
        {
            int n = s.length();
            stack<char> st;
            int curr_max = 0, max = 0;
            for (int i = 0; i < n; i++)
            {
                if (!st.empty() && s[i] == ')')
                {
                    if (curr_max > 0)
                    {
                        curr_max--;
                    }
                    st.pop();
                }
                if (s[i] == '(')
                {
                    st.push(s[i]);
                    curr_max++;
                    if (curr_max > max) max = curr_max;
                }
            }

            if (!st.empty()) return -1;
            return max;
        }
};