class Solution {
    public int sumFourDivisors(int[] nums) {
        int n = 100000;
        int[][] divisors = new int[n+1][2]; 

        for(int i = 1; i*i <= n; i++){
            for(int j = i*i; j <= n; j+=i){
                divisors[j][0] += 1 + (i != j/i ? 1 : 0); // count of divisors of j
                divisors[j][1] += i + (i != j/i ? j/i : 0); // sum of divisors of j
            }
        }

        int res = 0;
        for(int num: nums){
            if(divisors[num][0] == 4){
                res += divisors[num][1];
            }
        }

        return res;
    }
}