class Solution {
    public double findMaxAverage(int[] nums, int k) {
        int n = nums.length;
        int left = 0, right = 0;
        int sum = 0, maxSum = Integer.MIN_VALUE;

        for(right = 0; right < n; right++){


            sum += nums[right];

            if(right - left + 1 == k){
                maxSum = Math.max(maxSum, sum);
                sum -= nums[left];
                left++;
            }
        }

        return (double) maxSum/k;
    }
}