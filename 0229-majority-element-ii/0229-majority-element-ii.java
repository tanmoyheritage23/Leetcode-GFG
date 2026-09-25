class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int cnt1 = 0, cnt2 = 0;
        int ele1 = Integer.MIN_VALUE, ele2 = Integer.MIN_VALUE;
        for(int num: nums){
            if(cnt1 == 0 && ele2 != num){
                cnt1 = 1;
                ele1 = num;
            } else if(cnt2 == 0 && ele1 != num){
                cnt2 = 1;
                ele2 = num;
            } else if(ele1 == num){
                cnt1++;
            } else if(ele2 == num){
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        int mini = nums.length / 3 + 1;
        cnt1 = 0; cnt2 = 0;
        for(int num: nums){
            if(ele1 == num){
                cnt1++;
            } else if(ele2 == num){
                cnt2++;
            }
        }

        List<Integer>result = new ArrayList<>();
        if(cnt1 >= mini) result.add(ele1);
        if(cnt2 >= mini) result.add(ele2);

        return result;
    }
}