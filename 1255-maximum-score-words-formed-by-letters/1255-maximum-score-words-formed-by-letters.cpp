class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for (int i = 0; i < score.size(); i++) {
            freq[i] = score[i]; // store scores directly by index
        }

        unordered_map<char, int> letterCount;
        for (char letter : letters) {
            letterCount[letter]++;
        }

        int maxScore = 0;
        vector<string> currSet;
        findMaxScore(0, words, letterCount, freq, maxScore, currSet);

        return maxScore;
    }

private:
    void findMaxScore(int index, vector<string>& words, unordered_map<char, int>& letterCount, vector<int>& freq, int& maxScore, vector<string>& currSet) {
        if (index == words.size()) {
            maxScore = max(maxScore, calculateSum(currSet, freq));
            return;
        }

        unordered_map<char, int> temp(letterCount); // create a copy for backtracking

        // Include the current word if possible
        if (canForm(words[index], temp)) {
            currSet.push_back(words[index]);
            findMaxScore(index + 1, words, temp, freq, maxScore, currSet);
            currSet.pop_back();
        }

        // Exclude the current word
        findMaxScore(index + 1, words, letterCount, freq, maxScore, currSet);
    }

    bool canForm(const string& word, unordered_map<char, int>& letterCount) {

        for (char ch : word) {
            if (letterCount[ch] > 0) {
                letterCount[ch]--;    // update the original map to reflect the used letters
            } else {
                return false;
            }
        }


        return true;
    }

    int calculateSum(vector<string>& currSet, vector<int>& freq) {
        int sum = 0;
        for (const string& word : currSet) {
            for (char ch : word) {
                sum += freq[ch - 'a'];
            }
        }
        return sum;
    }
};
