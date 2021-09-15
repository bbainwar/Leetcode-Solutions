class Solution {
public:
    
    int solution(int n, vector<int>& dp){
        if(n<0){return 10005;}
        
        if(dp[n]!=-1){return dp[n];}
        int ans=INT_MAX;
        for(int i=1; i<=sqrt(n); i++){
            ans=min(ans, 1+solution(n-i*i, dp));
        }
        
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=0;
        return solution(n, dp);
    }
};