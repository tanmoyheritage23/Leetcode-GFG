class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int countPalindrome = 0;
        
        /* For substring length 1 */
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            countPalindrome++;
        }
        
        /* For substring length 2 */
        for(int i = 0; i < n-1; i++){
            dp[i][i+1] = s.charAt(i) == s.charAt(i+1);
            if(dp[i][i+1]) countPalindrome++;
        }
        
        /* For substring length > 2 */
        for(int len = 3; len <= n; len++){
            for(int i = 0,j = i+len-1; j < n; i++,j++){
                dp[i][j] = s.charAt(i) == s.charAt(j) && dp[i+1][j-1];
                if(dp[i][j]) countPalindrome++;
            }
        }
        
        return countPalindrome;
    }
}