class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, 1);
        for(int i=n-1; i>=0; i--){
            for(int j=i+1; j<n; j++){
                if(nums[j]>nums[i]){
                    ans[i]=max(ans[i], 1+ans[j]);
                }
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};