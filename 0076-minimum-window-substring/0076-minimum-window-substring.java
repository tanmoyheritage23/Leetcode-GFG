class Solution {
    public String minWindow(String s, String t) {
        int n = s.length();
        int m = t.length();
        String ans = "";
        if (m > n)
            return ans;

        int[] freq = new int[128];
        for (int i = 0; i < m; i++) {
            freq[t.charAt(i)]++;
        }

        int st = 0, end = 0, ansSt = 0, count = 0, minWindow = Integer.MAX_VALUE;

        while (end < n) {
            char ch = s.charAt(end);
            freq[ch]--;
            if (freq[ch] >= 0)
                count++;

            while (count == m) {
                if (end - st + 1 < minWindow) {
                    minWindow = end - st + 1;
                    ansSt = st;
                }
                freq[s.charAt(st)]++;
                if (freq[s.charAt(st)] > 0)
                    count--;
                st++;
            }

            end++;

        }

        ans = minWindow == Integer.MAX_VALUE ? "" : s.substring(ansSt, ansSt+minWindow);
        return ans;

    }
}