
class Solution {

    public int maxCapacity(int[] costs, int[] capacity, int budget) {
        int n = costs.length;

        int[][] machines = new int[n][2];

        for (int i = 0; i < n; i++) {
            machines[i][0] = costs[i];
            machines[i][1] = capacity[i];
        }

        Arrays.sort(machines, (a, b) -> b[0] - a[0]);

        int maxCap = 0;


        for (int i = 0; i < n; i++) {
            if (machines[i][0] < budget) {
                maxCap = Math.max(maxCap, machines[i][1]);
            }
        }

        int[] suffixMaxCapacity = new int[n];
        suffixMaxCapacity[n-1] = machines[n-1][1];

        for(int i = n - 2; i >= 0; i--){
            suffixMaxCapacity[i] = Math.max(machines[i][1],suffixMaxCapacity[i+1]);
        }

       
        int right = n;

        for(int i = 0; i < n; i++) {
            int remainingBudget = budget - machines[i][0];

            if(remainingBudget < 0) continue;

            right = Math.max(i+1,right);

            while(right-1 > i && machines[right-1][0] < remainingBudget) right--;
            if(right==n) continue;

            maxCap = Math.max(maxCap,machines[i][1] + suffixMaxCapacity[right]);
        }

        return maxCap;
    }
}