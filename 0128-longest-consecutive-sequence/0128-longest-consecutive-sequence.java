class Solution {
    public int longestConsecutive(int[] nums) {
         if (nums.length == 0) return 0; // Edge case: Empty array

        Set<Integer> numSet = new HashSet<>();
        for (int num : nums) {
            numSet.add(num);
        }

        int maxLength = 0;

        for (int num : numSet) {
            
            if (!numSet.contains(num - 1)) { // This num could be the staring point 
                int currentNum = num;
                int count = 1;

                // Count consecutive numbers
                while (numSet.contains(currentNum + 1)) {
                    currentNum++;
                    count++;
                }

                maxLength = Math.max(maxLength, count);
            }
        }

        return maxLength;
    }
}