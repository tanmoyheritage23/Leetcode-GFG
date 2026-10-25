class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        // -4,-1,-1,0,1,2
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>>ans = new ArrayList<>();
        for(int i = 0; i < n - 2; i++) {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1; int right = n - 1;
            while(left < right) {
                List<Integer>triplets = new ArrayList<>();
                int sum = nums[i] + nums[left] + nums[right];
                if( sum == 0) {
                    triplets.add(nums[i]);
                    triplets.add(nums[left]);
                    triplets.add(nums[right]);
                    ans.add(triplets);
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) left++;
                    while(left < right && nums[right] == nums[right + 1]) right--;
                }
                else if(sum < 0) left++;
                else right--;
            }
            
        }
        return ans;
    }
}