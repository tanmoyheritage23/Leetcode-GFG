class Solution
{
    public:
        bool checkValidString(string s)
        {
            int n = s.length();
            int openBracket = 0, closeBracket = 0;

            for (int i = 0; i < n; i++)
            {
                if (s[i] == '(' || s[i] == '*')
                {
                    openBracket++;
                }
                else
                {
                    openBracket--;
                }

                if (s[n - 1 - i] == ')' || s[n - 1 - i] == '*')
                {
                    closeBracket++;
                }
                else
                {
                    closeBracket--;
                }
               	// openBracket < 0 means ')' surplus and closeBracket < 0 means '(' surplus so invalid.
                if (openBracket < 0 || closeBracket < 0) return false;
            }

            return true;
        }
};