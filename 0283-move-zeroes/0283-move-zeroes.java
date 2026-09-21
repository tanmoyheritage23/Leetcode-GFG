class Solution {
    public void moveZeroes(int[] nums) {
        int zeroPosition = 0;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != 0){
                swap(i,zeroPosition,nums);
                zeroPosition++;
            }
        }
    }

    private void swap(int i, int j, int[] nums){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}