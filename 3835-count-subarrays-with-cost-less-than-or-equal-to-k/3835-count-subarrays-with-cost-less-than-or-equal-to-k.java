class Solution {
    public long countSubarrays(int[] nums, long k) {
        int n = nums.length;
        ArrayDeque<Integer> maxq = new ArrayDeque<Integer>(); // decreasing
        ArrayDeque<Integer> minq = new ArrayDeque<Integer>(); // increasing
        int st = 0; long count = 0;
        

        for(int end = 0; end < n; end++) {
            while(!maxq.isEmpty() && nums[maxq.peekLast()] <= nums[end]) maxq.pollLast();
            maxq.addLast(end);

            while(!minq.isEmpty() && nums[minq.peekLast()] >= nums[end]) minq.pollLast();
            minq.addLast(end);

            while(st <= end && (long)(end - st + 1) * ((long)nums[maxq.peekFirst()] - (long)nums[minq.peekFirst()]) > k){

            if(!maxq.isEmpty() && maxq.peekFirst() <= st) maxq.pollFirst();
            if(!minq.isEmpty() && minq.peekFirst() <= st) minq.pollFirst();

            st++;

            }

            count += end - st + 1;
        }

        return count;
    }
}