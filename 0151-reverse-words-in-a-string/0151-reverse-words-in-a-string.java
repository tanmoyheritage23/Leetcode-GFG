class Solution {
    public String reverseWords(String s) {
        // Convert string to char array for in-place modifications
        char[] str = s.toCharArray();

        // Step 1: Reverse entire string
        reverse(str, 0, str.length - 1);

        // Step 2: Reverse each word
        reverseWords(str);

        // Step 3: Clean up spaces and return the cleaned string
        String result = new String(str).trim();
        
        String[] resultArray = result.split("\\s+");

        String ans = String.join(" ",resultArray);

        return ans;
    }

     private void reverse(char[] str, int left, int right) {
        while (left < right) {
            char temp = str[left];
            str[left++] = str[right];
            str[right--] = temp;
        }
    }

    private void reverseWords(char[] s) {
        int n = s.length;
        int start = 0;
        for (int end = 0; end < n; end++) {
            // Find the end of the current word
            if (s[end] == ' ') {
                reverse(s, start, end - 1);
                start = end + 1; // Move to the start of the next word
            }
        }
        // Reverse the last word
        reverse(s, start, n - 1);
    }
}