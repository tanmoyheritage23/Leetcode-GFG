class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int low = 1, high = 0;
        int n = piles.length;
        for(int i = 0; i < n; i++){
            high = Math.max(high,piles[i]);
        }

        while(low < high){
            int mid = low + (high - low) / 2;
            if(check(mid,n,piles) <= h){
                high = mid;
            }else low = mid + 1;
        }
        return low;
    }

    private int check(int count,int n, int[] piles){
        int hour = 0;
        for(int i = 0; i < n; i++){
            int banana = piles[i];
            int div = banana/count;
            int rem = banana%count;
            hour = hour + div + (rem == 0 ? 0 : 1);
        }
        return hour;
    }
}