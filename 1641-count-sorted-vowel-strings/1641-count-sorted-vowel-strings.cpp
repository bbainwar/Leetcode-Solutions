class Solution {
public:
    int dp[55][6];
    int sol(int l, int s){
        if(s==1) return l;
        if(l==0 || s<1) return 0;
        if(dp[s][l]!=-1) return dp[s][l];
        return dp[s][l]=sol(l, s-1)+sol(l-1, s);
    }
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return sol(5, n);
    }
};