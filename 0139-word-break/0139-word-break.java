class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();

        boolean[] dp = new boolean[n+1];
        dp[0] = true;

        for(int i = 1; i <= n; i++){
            for(String word: wordDict){
                int start = i - word.length();
                if(start >= 0 && dp[start] && s.substring(start,i).equals(word)){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
}