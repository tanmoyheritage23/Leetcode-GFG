class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
            int st = 0, end = 0, ans = 0;
            int[] freq= new int[128];

            while (end < n)
            {
                freq[s.charAt(end)]++;
                while (freq[s.charAt(end)] > 1)
                {
                    freq[s.charAt(st)]--;
                    st++;
                }

                ans = Math.max(ans, end - st + 1);
                end++;
            }

            return ans;
    }
}