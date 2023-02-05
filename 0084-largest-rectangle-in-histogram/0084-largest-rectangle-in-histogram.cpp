class Solution
{
    /*T.C => O(N*N), S.C => O(1) 
        Prefer notes for better understanding
       public:
           int largestRectangleArea(vector<int> &heights)
           {
               int n = heights.size();
               int maxArea = 0;

               for (int i = 0; i < n; i++)
               {
                   int curr = heights[i];
                   int prevSmallerInd = i, nextSmallerInd = i;
                   int j = i, k = i;
                   while (j >= 0 && heights[j] >= curr) j--, prevSmallerInd = j;
                   while (k < n && heights[k] >= curr) k++, nextSmallerInd = k;
                   int area = curr *(nextSmallerInd - prevSmallerInd - 1);
                   maxArea = max(area, maxArea);
               }

               return maxArea;
           }
           */
    public:
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
                if (st.empty()) leftSmall[i] = 0;
                else leftSmall[i] = st.top() + 1;
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
                if (st.empty()) rightSmall[i] = n - 1;
                else rightSmall[i] = st.top() - 1;
                st.push(i);
            }
            int maxArea = 0;
            for (int i = 0; i < n; i++)
            {
                int area = heights[i] *(rightSmall[i] - leftSmall[i] + 1);
                maxArea = max(maxArea, area);
            }
            return maxArea;
        }
};