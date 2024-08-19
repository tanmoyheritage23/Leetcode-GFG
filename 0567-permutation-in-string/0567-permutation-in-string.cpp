class Solution
{
    private:
        bool matches(vector<int>&s1freq, vector<int>&s2freq)
        {
            for (int i = 0; i < 26; i++)
            {
                if (s1freq[i] != s2freq[i]) return false;
            }

            return true;
        }
    public:
        bool checkInclusion(string s1, string s2)
        {
            if (s1.length() > s2.length()) return false;
            vector<int>s1freq(26,0);
            vector<int>s2freq(26,0);

            for (int i = 0; i < s1.length(); i++)
            {
                s1freq[s1[i] - 'a']++;
                s2freq[s2[i] - 'a']++;
            }

            for (int i = 0; i <= s2.length() - s1.length(); i++)
            {
                if (matches(s1freq, s2freq)) return true;
                if (i + s1.length() < s2.length())
                {
                    s2freq[s2[i + s1.length()] - 'a']++;
                    s2freq[s2[i] - 'a']--;
                }
            }

            return false;
        }
};