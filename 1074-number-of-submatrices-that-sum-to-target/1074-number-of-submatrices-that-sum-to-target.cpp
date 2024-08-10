class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>subMatrixSum(n+1,vector<int>(m+1,0));
        
        for(int row = 1; row <= n; row++){
            for(int col = 1; col <= m; col++){
                subMatrixSum[row][col] = matrix[row-1][col-1] + subMatrixSum[row-1][col] + subMatrixSum[row][col-1] - subMatrixSum[row-1][col-1];
            }
        }
        
        int res = 0;
        
        for(int r1 = 1; r1 <= n; r1++){
            for(int r2 = r1; r2 <= n; r2++){
                for(int c1 = 1; c1 <= m; c1++){
                    for(int c2 = c1; c2 <= m; c2++){
                        int currSum = subMatrixSum[r2][c2] - subMatrixSum[r1-1][c2] -subMatrixSum[r2][c1-1] +  subMatrixSum[r1-1][c1-1];
                        if(currSum == target) res++;
                    }
                }
            }
        }
        
        return res;
        
    }
};