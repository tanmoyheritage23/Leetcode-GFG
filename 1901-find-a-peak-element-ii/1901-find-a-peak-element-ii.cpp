class Solution
{
    private:
        int findMaxNumberRowIndex(vector<vector < int>> &mat, int row, int mid)
        {
            int maxVal = -1;
            int ind = -1;

            for (int i = 0; i < row; i++)
            {
                if (mat[i][mid] > maxVal)
                {
                    maxVal = mat[i][mid];
                    ind = i;
                }
            }

            return ind;
        }
    public:
        vector<int> findPeakGrid(vector<vector < int>> &mat)
        {
            int row = mat.size();
            int col = mat[0].size();

            int low = 0;
            int high = col - 1;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int maxElementInd = findMaxNumberRowIndex(mat, row, mid);
                int left = mid - 1 >= 0 ? mat[maxElementInd][mid - 1]: - 1;
                int right = mid + 1 < col ? mat[maxElementInd][mid + 1] : -1;

                if (mat[maxElementInd][mid] > left && mat[maxElementInd][mid] > right) return {
                    maxElementInd,
                    mid
                };
                else if (mat[maxElementInd][mid] < left) high = mid - 1;
                else low = mid + 1;
            }

            return { -1,
                -1 };
        }
};