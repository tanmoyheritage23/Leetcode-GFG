class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int n = words.length;
        int[] arr = new int[n];
        
        for (int i = 0; i < n; i++) {
            String word = words[i];
            int l = word.length() - 1;
            
            // Use .charAt() instead of []
            if (isVowel(word.charAt(0)) && isVowel(word.charAt(l))) {
                arr[i] = 1;
            }
        }

        int[] psum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            psum[i + 1] = arr[i] + psum[i];
        }

        int[] ans = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            ans[i] = psum[queries[i][1] + 1] - psum[queries[i][0]];
        }
        return ans;
    }

    // Helper method to keep the IF statement clean
    private boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}