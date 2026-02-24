class Solution {
    public int uniquePaths(int m, int n) {
        int[] prev = new int[n]; 
        for(int i=0;i<m;i++){
            int[] curr = new int[n];
            for(int j=0;j<n;j++){
                if(i==0 || j==0) curr[j]=1;
                else curr[j] = prev[j] + curr[j -1];
            }
            prev=curr;
        }
        return prev[n-1];
    }
}