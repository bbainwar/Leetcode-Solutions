class Solution {
public:
    int dp[70][70][70];
        int cherryPickup(vector<vector<int>>& grid) {
            int row = grid.size(), col = grid[0].size();
            memset(dp, 0, sizeof(dp));
            for(int r = row - 1; r >= 0; --r) {
                for(int c1 = 0; c1 < col; ++c1) {
                    for(int c2 = 0; c2 < col; ++c2) {
                        for(int dir1 : {-1, 0, 1}) {
                            for(int dir2 : {-1, 0, 1}) {
                                int tmp_c1 = c1 + dir1, tmp_c2 = c2 + dir2;
                                if(tmp_c1 >= 0 && tmp_c1 < col && tmp_c2 >= 0 && tmp_c2 < col)
                                    dp[r][c1][c2] = max(dp[r][c1][c2], dp[r + 1][tmp_c1][tmp_c2]);
                            }
                        }
                        dp[r][c1][c2] += grid[r][c1] + grid[r][c2] * (c1 != c2);
                    }
                }
            }

            return dp[0][0][col - 1];
        }
};