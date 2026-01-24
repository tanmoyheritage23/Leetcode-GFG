class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();
        mp.put(0,1);
        int count = 0, currSum = 0;
        for(int num: nums){
            currSum += num;
            if(mp.containsKey(currSum - k)) count += mp.get(currSum - k);
            mp.put(currSum, mp.getOrDefault(currSum,0) + 1);
        }

        return count;
    }
}