class Solution
{
    private:
        bool isValid(string &s)
        {
            stack<char> st;
            int strSize = s.length();
            for (int i = 0; i < strSize; i++)
            {
                if (s[i] == '(') st.push(s[i]);
                else
                {
                    if (s[i] == ')')
                    {
                        if (st.empty()) return false;
                        if (st.top() == '(')
                        {
                            st.pop();
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
            }

            if (st.empty()) return true;
            return false;
        }
    public:
        vector<string> removeInvalidParentheses(string s)
        {
            queue<string> q;
            q.push(s);
            set<string> unique;
            vector<string> ans;

            if (isValid(s))
            {
                ans.push_back(s);
                return ans;
            }

            while (true)
            {
                int queueSize = q.size();

                while (queueSize--)
                {
                    string st = q.front();
                    q.pop();
                    int strSize = st.length();
                    for (int i = 0; i < strSize; i++)
                    {
                        if (st[i] != ')' && st[i] != '(') continue;
                        string newSt = st.substr(0, i) + st.substr(i + 1);
                        if (unique.find(newSt) == unique.end())
                        {
                            q.push(newSt);
                            unique.insert(newSt);
                            if (isValid(newSt))
                            {
                                ans.push_back(newSt);
                            }
                        }
                    }
                }

                if (ans.size() > 0) break;
            }

            return ans;
        }
};