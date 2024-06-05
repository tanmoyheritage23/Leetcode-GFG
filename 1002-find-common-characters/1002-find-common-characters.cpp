class Solution
{
    public:
        vector<string> commonChars(vector<string> &word)
        {
            vector<int> commonChar(26,0);
            vector<int> currChar(26,0);

            for (char ch: word[0])
            {
                commonChar[ch - 'a']++;
            };

            for (int i = 1; i < word.size(); i++)
            {
                
                fill(currChar.begin(),currChar.end(),0);

                for (char ch: word[i])
                {
                    currChar[ch - 'a']++;
                }
               	// updating common character list at each index
                for (int i = 0; i < 26; i++)
                {
                    commonChar[i] = min(currChar[i], commonChar[i]);
                }
            }

            vector<string> result;

            for (int i = 0; i < 26; i++)
            {
                for (int j = 0; j < commonChar[i]; j++)
                {
                    result.push_back(string(1, i + 'a'));
                }
            }

            return result;
        }
};