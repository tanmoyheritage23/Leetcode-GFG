class Solution {

    public int minimumDeleteSum(String s1, String s2) {
        int n = s1.length();
        int m = s2.length();

        int[][] dp = new int[n+1][m+1];
        // Base case 
        for(int i = n - 1; i >= 0; i--){
            dp[i][m] = dp[i+1][m] + s1.charAt(i);
        }
        for(int j = m - 1; j >= 0; j--){
            dp[n][j] = dp[n][j+1] + s2.charAt(j);
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int ans = Integer.MAX_VALUE;
                if (s1.charAt(i) == s2.charAt(j)) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int deleteS1 = s1.charAt(i) + dp[i + 1][j];
                    int deleteS2 = s2.charAt(j) + dp[i][j + 1];
                    ans = Math.min(deleteS1, deleteS2);
                }
                dp[i][j] = ans;

            }
        }
        
        return dp[0][0];
        
    }
}