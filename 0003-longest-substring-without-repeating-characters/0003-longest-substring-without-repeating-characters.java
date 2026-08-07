class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character,Integer>mp = new HashMap<>();
        int n = s.length();
        int st = 0, end = 0;
        int maxLength = 0;

        while(end < n){
            char ch = s.charAt(end);
            mp.put(ch,mp.getOrDefault(ch,0)+1);
            while(mp.get(ch) > 1){
                char curr = s.charAt(st);
                mp.put(curr,mp.get(curr)-1);
                st++;
            }
            maxLength = Math.max(maxLength, end - st + 1);
            end++;

        }
        return maxLength;
    }
}