class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;
        List<int[]>digitSum = new ArrayList<>();
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num = num/10;
            }
            digitSum.add(new int[]{sum,i});
        }
        Collections.sort(digitSum, new Comparator<int[]>(){
           public int compare(int[] a, int[] b){
            if(a[0] != b[0]){
                return Integer.compare(a[0],b[0]);
            }else{
                return Integer.compare(nums[a[1]],nums[b[1]]);
            }
           }
        });
        
        int swaps = 0;
        int i = 0;

        while(i < n){
            int index = digitSum.get(i)[1];
            if(i < n && index != i){
                int[] temp = digitSum.get(i); // 3
                digitSum.set(i,digitSum.get(index));
                digitSum.set(index,temp);
                swaps++;
            }
            else i++;
        }

        return swaps;
        
    }
}