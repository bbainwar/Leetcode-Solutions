class Solution {
public:
    int soln(int n, vector<int>& dp){
        if(dp[n]!=-1){return dp[n];}
        if(n==0){return dp[n]=1;}
        int ans=0;
        for(int i=0; i<n; i++){
            ans=ans+soln(i, dp)*soln(n-1-i, dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int> dp(20, -1);
        return soln(n, dp);
    }
};