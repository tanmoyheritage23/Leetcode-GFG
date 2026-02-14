class Solution {
    public int numDecodings(String s) {
        if(s == null || s.length() == 0 || s.charAt(0) == '0') return 0;

        int n = s.length();
        // dp[i] is equal to the number of ways to decode the first i characters of the string s
        int[] dp = new int[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            int digit = Character.getNumericValue(s.charAt(i - 1));
            if(digit != 0) dp[i] += dp[i - 1];

            digit = Integer.parseInt(s.substring(i - 2, i));
            if(digit >= 10 && digit <= 26) dp[i] += dp[ i - 2];
        }
        
        return dp[n];
    }
}