class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;

        int m = grid.size();
        int n = grid[0].size();

        // dp[i][j][0] = ways reaching (i,j) while moving right
        // dp[i][j][1] = ways reaching (i,j) while moving down
        vector<vector<array<long long, 2>>> dp(
            m, vector<array<long long, 2>>(n, {0, 0})
        );

        // First move from (0,0)
        if (n > 1)
            dp[0][1][0] = 1;

        if (m > 1)
            dp[1][0][1] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                // -------------------------
                // Arrived moving RIGHT
                // -------------------------
                long long right = dp[i][j][0];

                if (right) {
                    if (grid[i][j] == 1) {
                        // Mirror:
                        // right -> down
                        if (i + 1 < m) {
                            dp[i + 1][j][1] =
                                (dp[i + 1][j][1] + right) % MOD;
                        }
                    }
                    else {
                        // Empty cell:
                        // Can choose RIGHT
                        if (j + 1 < n) {
                            dp[i][j + 1][0] =
                                (dp[i][j + 1][0] + right) % MOD;
                        }

                        // Or choose DOWN
                        if (i + 1 < m) {
                            dp[i + 1][j][1] =
                                (dp[i + 1][j][1] + right) % MOD;
                        }
                    }
                }

                // -------------------------
                // Arrived moving DOWN
                // -------------------------
                long long down = dp[i][j][1];

                if (down) {
                    if (grid[i][j] == 1) {
                        // Mirror:
                        // down -> right
                        if (j + 1 < n) {
                            dp[i][j + 1][0] =
                                (dp[i][j + 1][0] + down) % MOD;
                        }
                    }
                    else {
                        // Empty cell:
                        // Can choose RIGHT
                        if (j + 1 < n) {
                            dp[i][j + 1][0] =
                                (dp[i][j + 1][0] + down) % MOD;
                        }

                        // Or choose DOWN
                        if (i + 1 < m) {
                            dp[i + 1][j][1] =
                                (dp[i + 1][j][1] + down) % MOD;
                        }
                    }
                }
            }
        }

        return (dp[m - 1][n - 1][0] +
                dp[m - 1][n - 1][1]) % MOD;
        
    }
};