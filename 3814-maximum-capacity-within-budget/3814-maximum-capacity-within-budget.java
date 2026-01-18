class Solution {

    public int maxCapacity(int[] costs, int[] capacity, int budget) {
        int n = costs.length;

        // Combine cost and capacity into one array
        int[][] machines = new int[n][2];

        for (int i = 0; i < n; i++) {
            machines[i][0] = costs[i];      // cost
            machines[i][1] = capacity[i];   // capacity
        }

        // Sort by cost in DESCENDING order
        Arrays.sort(machines, (a, b) -> b[0] - a[0]);

        int maxCap = 0;

        // Case 1: Consider single machine
        for (int i = 0; i < n; i++) {
            if (machines[i][0] < budget) {
                maxCap = Math.max(maxCap, machines[i][1]);
            }
        }

        // Build suffix maximum capacity array
        int[] suffixMax = new int[n];
        suffixMax[n - 1] = machines[n - 1][1];

        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = Math.max(machines[i][1], suffixMax[i + 1]);
        }

        // Case 2: Try picking two machines
        int right = n;

        for (int i = 0; i < n; i++) {

            int remaining = budget - machines[i][0];

            // If this machine itself is too costly, skip
            if (remaining <= 0)
                continue;

            // Ensure right pointer is always ahead of i
            right = Math.max(right, i + 1);

            // Move right pointer to valid position
            while (right - 1 > i && machines[right - 1][0] < remaining) {
                right--;
            }

            // If no valid partner found, continue
            if (right == n)
                continue;

            // Combine current machine with best possible partner
            int combinedCapacity = machines[i][1] + suffixMax[right];

            maxCap = Math.max(maxCap, combinedCapacity);
        }

        return maxCap;
    }
}