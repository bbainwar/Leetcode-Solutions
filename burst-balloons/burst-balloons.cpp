class Solution {
public:
    int maxCoins(vector<int>& A) {
        int N=A.size();
        int B[N + 2];
 
        B[0] = 1;
        B[N + 1] = 1;

        for (int i = 1; i <= N; i++)
            B[i] = A[i - 1];

        // Declare DP Array
        int dp[N + 2][N + 2];
        memset(dp, 0, sizeof(dp));

        for (int length = 1; length < N + 1; length++)
        {
            for (int left = 1; left < N - length + 2; left++)
            {
                int right = left + length - 1;
                // For a sub-array from indices left, right
                // This innermost loop finds the last balloon burst
                for (int last = left; last < right + 1; last++)
                {
                    dp[left][right] = max(dp[left][right],
                                          dp[left][last - 1] +
                                          B[left - 1] * B[last] * B[right + 1] +
                                          dp[last + 1][right]);
                }
            }
        }
        return dp[1][N];
        }
};