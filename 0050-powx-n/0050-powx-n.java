class Solution {
    public double myPow(double x, int n) {
        double ans = 1.0;
        long N = n;
        if(n < 0) N = -1 * N; // for integer overflow

        while(N > 0){
            if(N % 2 == 1){
                ans = ans * x;
                N = N - 1;
            }
            else{
                x = x*x;
                N = N/2;
            }
        }

        return n<0 ? 1/ans : ans;

    }
}