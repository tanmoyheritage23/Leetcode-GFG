class Solution {
    public int singleNumber(int[] nums) {
        int result = 0; // Initialize result which will hold our single number

        // XOR all elements; duplicates will cancel out
        for (int num : nums) {
            result ^= num; // XORing each number with the result
        }

        return result; // The resulting XOR is the single number
    }
}