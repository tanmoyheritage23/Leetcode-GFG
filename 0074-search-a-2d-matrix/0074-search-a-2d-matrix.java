class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;
        
        int m = matrix.length;
        int n = matrix[0].length;
        
        int start = 0;
        int end = m * n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            // Map 1D index 'mid' to 2D coordinates (row, col)
            int row = mid / n;
            int col = mid % n;
            
            int midValue = matrix[row][col];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                // Target is in the upper half (conceptually right side of 1D array)
                start = mid + 1;
            } else {
                // Target is in the lower half (conceptually left side of 1D array)
                end = mid - 1;
            }
        }
        return false;
    }
}