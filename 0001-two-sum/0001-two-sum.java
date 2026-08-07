class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> mp = new HashMap<>();
        int n = nums.length;
        int[] ans = new int[2];
        for(int i = 0; i < n; i++){
            int missingNum = target - nums[i];
            if(mp.containsKey(missingNum)){
                ans[0] = i;
                ans[1] = mp.get(missingNum);
                break;
            }
            mp.put(nums[i], i);
        }
        return ans;

    }
}