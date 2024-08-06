class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLength = words[i].length();
            int j = i + 1;
            while (j < n && lineLength + words[j].length() + (j - i) <= maxWidth) {
                lineLength += words[j].length();
                j++;
            }

            string line;
            int spaces = maxWidth - lineLength;
            int gaps = j - i - 1;

            if (gaps == 0 || j == n) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int spaceBetween = spaces / gaps;
                int extraSpaces = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spaceBetween + (k - i < extraSpaces ? 1 : 0), ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};