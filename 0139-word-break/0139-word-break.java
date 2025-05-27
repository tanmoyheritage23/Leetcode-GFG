class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        Boolean[] memo = new Boolean[s.length()];
        return canBreak(s, 0, wordDict, memo);
    }

    private boolean canBreak(String s, int start, List<String> wordDict, Boolean[] memo) {
        if (start == s.length()) return true;
        if (memo[start] != null) return memo[start];

        for (String word : wordDict) {
            int end = start + word.length();
            if (end <= s.length() && s.substring(start, end).equals(word)) {
                if (canBreak(s, end, wordDict, memo)) {
                    //memo[start] = true;
                    return true;
                }
            }
        }

        memo[start] = false;
        return false;
    }
}