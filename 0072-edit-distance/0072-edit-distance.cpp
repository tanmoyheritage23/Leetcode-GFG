class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) {
            return 0;
        }
        if (word1.empty() || word2.empty()) {
            return 1;
        }
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        
        // base cases (convert to empty string w/ deletions), dist is just length
        for (int i = 1; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 1; j <= n; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    // no operation needed, same char
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // min(replace, delete, insert) + 1 <-- since an op was needed
                    int deletion = 1 + dp[i-1][j];
                    int insertion = 1 + dp[i][j-1];
                    int replacement = 1 + dp[i-1][j-1];
                    dp[i][j] = min(deletion, min(insertion, replacement));
                }
            }
        }
        
        return dp[m][n];
    }
};