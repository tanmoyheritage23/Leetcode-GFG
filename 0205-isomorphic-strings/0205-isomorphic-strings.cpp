class Solution
{
    public:
        bool isIsomorphic(string s, string t)
        {
            int n = s.length();
            string changedS = "";
            unordered_map<char, char> mp1, mp2;
            for (int i = 0; i < n; i++)
            {
                if (!mp1[t[i]] && !mp2[s[i]]) mp1[t[i]] = s[i], mp2[s[i]] = t[i];
                else if (mp2[s[i]] != t[i] || mp1[t[i]] != s[i]) return false;
            }
            return true;;
        }
};