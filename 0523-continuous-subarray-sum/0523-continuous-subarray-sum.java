class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer,Integer>multipleMapper = new HashMap<>();
        int i = 0; int currSum = 0;
        multipleMapper.put(0,-1);

        while(i < n){
            currSum += nums[i];
            int remainder = currSum % k;

            if(multipleMapper.containsKey(remainder)){
                int subarrayLength = i - multipleMapper.get(remainder);
                if(subarrayLength > 1) return true;
            }

            else multipleMapper.put(remainder,i);
            i++;

        }

        return false;
    }
}