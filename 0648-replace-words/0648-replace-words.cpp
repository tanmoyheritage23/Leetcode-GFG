class Solution
{
    public:
        string replaceWords(vector<string> &dictionary, string sentence)
        {
            stringstream ss(sentence);
            unordered_set<string> dictSet(dictionary.begin(), dictionary.end());
            string word = "";
            string newSentence = "";
            while (getline(ss, word, ' '))
            {
                newSentence += shortestRoot(word, dictSet) + " ";
            }
            newSentence.pop_back();
            return newSentence;
        }

    private:
        string shortestRoot(string &word, unordered_set<string> &dictSet)
        {
            for (int i = 1; i <= word.size(); i++)
            {
                string root = word.substr(0, i);
                if (dictSet.contains(root))
                {
                    return root;
                }
            }

            return word;
        }
};