class Solution {
public:
    long long dp[55][55][55];
    long long solution(int m, int n, int maxMove, int startRow, int startColumn){
        if(startRow<0 || startRow>=m || startColumn<0 || startColumn>=n) return 1;
        if(maxMove==0) return 0;
        if(dp[maxMove][startRow][startColumn]!=-1) return dp[maxMove][startRow][startColumn];
        
        long long top=solution(m, n, maxMove-1, startRow-1, startColumn);
        long long left=solution(m, n, maxMove-1, startRow, startColumn-1);
        long long down=solution(m, n, maxMove-1, startRow+1, startColumn);
        long long right=solution(m, n, maxMove-1, startRow, startColumn+1);
        top=top%(1000000007);
        down=down%(1000000007);
        left=left%(1000000007);
        right=right%(1000000007);
        return dp[maxMove][startRow][startColumn]=(top+down+left+right)%(1000000007);
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solution(m, n, maxMove, startRow, startColumn)%1000000007;
    }
};