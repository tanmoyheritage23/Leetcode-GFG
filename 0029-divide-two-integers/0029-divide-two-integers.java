class Solution {
    public int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;

        boolean sign = true;
        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) sign = false;
        int ans = 0;
        long n = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);
        while(n >= b){
            int count = 0;
            while(n > (b << (count + 1))) count++;
            ans += (1 << count);
            n -= (b << count);
        }

        if( ans == (1 << 31) && sign) return Integer.MAX_VALUE;
        if( ans == (1 << 31) && !sign) return Integer.MIN_VALUE;

        return sign ? ans : (-1) * ans;

    }
}