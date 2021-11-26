class Solution {
public:
    
    int dp[105];
    int solution(vector<int> nums, int s){
        int n=nums.size();
        if(s>=n)
            return 0;
        if(dp[s]!=-1)
            return dp[s];
        return dp[s]=max(nums[s]+solution(nums, s+2), solution(nums, s+1));
    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        memset(dp, -1, sizeof(dp));
        int n=nums.size();
        int a1 = solution(nums, 1);
        nums.pop_back();
        memset(dp, -1, sizeof(dp));
        int a2 = solution(nums, 0);
        return max(a1, a2);
    }
};