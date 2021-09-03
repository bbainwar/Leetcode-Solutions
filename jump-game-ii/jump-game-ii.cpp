class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 10005);
        dp[n-1]=0;
        for(int i=n-2; i>=0; i--){
            for(int j=i+1; j<=i+nums[i]&&j<n; j++){
                dp[i]=min(dp[i], 1+dp[j]);
            }
        }
        return dp[0];
    }
};