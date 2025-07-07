class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();        // rows
        int n = obstacleGrid[0].size();     // columns

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If there is an obstacle
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                // Starting cell
                else if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                }
                // First row
                else if (i == 0) {
                    dp[i][j] = dp[i][j - 1];
                }
                // First column
                else if (j == 0) {
                    dp[i][j] = dp[i - 1][j];
                }
                // Rest of the grid
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
