class Solution {
public:
    int dp[105][105];
    int solution(vector<vector<int>>& obstacleGrid, int r, int c){
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        if(r>=n || c>=m) return 0;
        if(obstacleGrid[r][c]==1) return 0;
        if(r==n-1 && c==m-1) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        
        return dp[r][c] = solution(obstacleGrid, r+1, c)+solution(obstacleGrid, r, c+1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp, -1, sizeof(dp));
        return solution(obstacleGrid, 0, 0);
    }
};