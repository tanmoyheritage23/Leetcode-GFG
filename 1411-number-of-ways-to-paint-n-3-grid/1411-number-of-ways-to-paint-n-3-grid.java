import java.util.*;

class Solution {

    static final int MOD = 1_000_000_007;

    public int numOfWays(int n) {

        List<int[]> patterns = new ArrayList<>();

        // Step 1: generate all valid rows (3^3 brute force)
        for (int a = 1; a <= 3; a++) {
            for (int b = 1; b <= 3; b++) {
                for (int c = 1; c <= 3; c++) {
                    if (a != b && b != c) {
                        patterns.add(new int[]{a, b, c});
                    }
                }
            }
        }

        int P = patterns.size();   // will be 12

        // Step 2: precompute which patterns can sit above each other
        boolean[][] ok = new boolean[P][P];

        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                boolean valid = true;
                for (int k = 0; k < 3; k++) {
                    if (patterns.get(i)[k] == patterns.get(j)[k]) {
                        valid = false;
                        break;
                    }
                }
                ok[i][j] = valid;
            }
        }

        // Step 3: DP table
        long[][] dp = new long[n][P];

        // first row
        for (int i = 0; i < P; i++) {
            dp[0][i] = 1;
        }

        // build rows 1..n-1
        for (int r = 1; r < n; r++) {
            for (int cur = 0; cur < P; cur++) {
                for (int prev = 0; prev < P; prev++) {
                    if (ok[prev][cur]) {
                        dp[r][cur] = (dp[r][cur] + dp[r - 1][prev]) % MOD;
                    }
                }
            }
        }

        // sum last row
        long ans = 0;
        for (int i = 0; i < P; i++) {
            ans = (ans + dp[n - 1][i]) % MOD;
        }

        return (int) ans;
    }
}