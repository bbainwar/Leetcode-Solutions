class Solution {
public:
    int ans=0;
    int dp[21][40005];
    int recur(vector<int>& nums, int target, int ind){
        if(ind>=nums.size()){
            if(target==0){
                return 1;
            }
            return 0;
        }
        int temp=target;
        if(target<0) temp=20000-target;
        if(dp[ind][temp]!=-1) return dp[ind][temp];
        return dp[ind][temp]=recur(nums, target+nums[ind], ind+1)+recur(nums, target-nums[ind], ind+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        return recur(nums, target, 0);
    }
};