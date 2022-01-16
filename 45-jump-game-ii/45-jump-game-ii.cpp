class Solution {
public:
    int min(int a, int b){
        return (a<b)?a:b;
    }
    int solution(vector<int>& nums, vector<int>& dp, int start){
        if(start>=nums.size()) return 100005;
        if(start==nums.size()-1) return 0;
        if(dp[start]!=-1) return dp[start];
        int ans=100005;
        for(int i=start+1; i<=min(start+nums[start], nums.size()-1); i++){
            ans=min(ans, 1+solution(nums, dp, i));
        }
        return dp[start]=ans;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solution(nums, dp, 0);
    }
};