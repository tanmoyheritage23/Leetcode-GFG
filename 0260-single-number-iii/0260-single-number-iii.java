class Solution {
    public int[] singleNumber(int[] nums) {
        // Step 1: XOR all numbers to get the result of two unique numbers XORed
        int xor = 0;
        for (int num : nums) {
            xor ^= num;
        }

        // Step 2: Find any bit that is set in the xor result (we'll use the rightmost
        // bit)
        int diff = xor & (-xor); // This finds the rightmost set bit

        // Step 3: Divide all numbers into two groups based on the found bit
        int[] result = new int[2];
        for (int num : nums) {
            if ((num & diff) == 0) {
                result[0] ^= num; // Group 1: with the bit not set
            } else {
                result[1] ^= num; // Group 2: with the bit set
            }
        }

        return result;
    }
}