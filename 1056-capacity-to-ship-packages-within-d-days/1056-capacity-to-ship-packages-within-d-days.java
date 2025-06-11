class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int low = Integer.MIN_VALUE;
        int high = 0;
        for(int weight: weights){
            low = Math.max(low,weight);
            high += weight;
        }

        while(low < high){
            int mid = low + (high - low)/ 2;
            int totaldays = helper(mid,weights);

            if(totaldays > days){
               low = mid + 1;
            }else{
                high = mid;
            }
        }

        return low;

    }

    private int helper(int capacity, int[] weights){
        int days = 1;
        int temp = 0;

        for(int weight: weights){
            if(temp + weight > capacity){
                days++;
                temp = 0;
            }
            temp += weight;
        }

        return days;
    }
}