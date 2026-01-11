class Solution {
    private:
int largestRectangleArea(vector<int> &heights)
        {
            int n = heights.size();
            vector<int> leftSmall(n), rightSmall(n);
            stack<int> st;

            for (int i = 0; i < n; i++)
            {
                int curr = heights[i];

                while (!st.empty() && curr <= heights[st.top()])
                {
                    st.pop();
                }
                if (st.empty()) leftSmall[i] = -1;
                else leftSmall[i] = st.top();
                st.push(i);
            }

            while (!st.empty()) st.pop();

            for (int i = n - 1; i >= 0; i--)
            {
                int curr = heights[i];

                while (!st.empty() && curr <= heights[st.top()])
                {
                    st.pop();
                }
                if (st.empty()) rightSmall[i] = n;
                else rightSmall[i] = st.top();
                st.push(i);
            }
            int maxArea = 0;
            for (int i = 0; i < n; i++)
            {
                int area = heights[i] *(rightSmall[i] - leftSmall[i] - 1);
                maxArea = max(maxArea, area);
            }
            return maxArea;
        }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] == '0') sum = 0;
                prefix[i][j] = sum;
            }
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++){
            maxArea = max(maxArea,largestRectangleArea(prefix[i]));

        }
        return maxArea;
    }
};