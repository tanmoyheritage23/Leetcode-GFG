class Solution {
public:
    vector<int> buildKMP(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;
        while (i < n) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                    // no increment of i
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    vector<vector<int>> kmpSearch(string& text, string& pattern) {
        int n = text.length();
        int m = pattern.length();
        vector<vector<int>> ans;

        int i = 0, j = 0;
        vector<int> lps = buildKMP(pattern);
        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            if (j == m) {
                ans.push_back({i - j, i - 1});
                j = lps[j - 1];
            } else if (i < n && text[i] != pattern[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return ans;
    }

    int countCells(vector<vector<char>>& grid, string pattern) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> mark_horizontal(n, vector<bool>(m, false));
        vector<vector<bool>> mark_vertical(n, vector<bool>(m, false));

        string horizontal = "";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                horizontal += grid[i][j];
            }
        }

        // cout << horizontal << endl;

        vector<vector<int>> horizontalQueries = kmpSearch(horizontal, pattern);
        // for (int i = 0; i < horizontalQueries.size(); i++) {
        //     for (int j = 0; j < 2; j++) {
        //         cout << horizontalQueries[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> horizontalPrefix(n * m + 1, 0);
        for (int i = 0; i < horizontalQueries.size(); i++) {
            int l = horizontalQueries[i][0];
            int r = horizontalQueries[i][1];
            horizontalPrefix[l]++;
            if (r + 1 < n * m + 1)
                horizontalPrefix[r + 1]--;
        }

        // for(int i = 0; i < horizontalPrefix.size(); i++){
        //     cout<<horizontalPrefix[i]<<endl;

        // }
        // cout<<"End"<<endl;

        vector<int> matchingHorizontalIndex(n * m + 1, 0);

        matchingHorizontalIndex[0] = horizontalPrefix[0];
        for (int i = 1; i < n * m + 1; i++) {
            matchingHorizontalIndex[i] =
                horizontalPrefix[i] + matchingHorizontalIndex[i - 1];
        }

        // for(int i = 0; i < matchingHorizontalIndex.size(); i++){
        //     cout<<matchingHorizontalIndex[i]<<endl;
        // }

        for (int i = 0; i < n * m; i++) {
            if (matchingHorizontalIndex[i] > 0) {
                int row = i / m;
                int col = i % m;
                mark_horizontal[row][col] = true;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << mark_horizontal[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        // cout << "---------" << endl;

        string vertical = "";
        for (int j = 0; j < m; j++) {
            for (int i = 0; i < n; i++) {
                vertical += grid[i][j];
            }
        }

        vector<vector<int>> verticalQueries = kmpSearch(vertical, pattern);
        vector<int> verticalPrefix(n * m + 1, 0);
        for (int i = 0; i < verticalQueries.size(); i++) {
            int l = verticalQueries[i][0];
            int r = verticalQueries[i][1];
            verticalPrefix[l]++;
            if (r + 1 < n * m + 1)
                verticalPrefix[r + 1]--;
        }

        vector<int> matchingVerticalIndex(n * m + 1, 0);
        matchingVerticalIndex[0] = verticalPrefix[0];
        for (int i = 1; i < n * m + 1; i++) {
            matchingVerticalIndex[i] =
                verticalPrefix[i] + matchingVerticalIndex[i - 1];
        }

        for (int i = 0; i < n * m; i++) {
            if (matchingVerticalIndex[i] > 0) {
                int row = i % n;
                int col = i / n;
                mark_vertical[row][col] = true;
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << mark_vertical[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int count = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (mark_horizontal[i][j] && mark_vertical[i][j])
                    count++;

        return count;
    }
};