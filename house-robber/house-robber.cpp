class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return nums[0];}
        if(n<3){
            return max(nums[0], nums[1]);
        }
        nums[n-3]+=nums[n-1];
        if(n==3){
            return max(nums[0], nums[1]);
        }
        for(int i=n-4; i>=0; i--){
            nums[i]+=max(nums[i+2], nums[i+3]);
        }
        
        int maxm=INT_MIN;
        for(int i: nums){
            maxm=max(maxm, i);
        }
        
        return maxm;
    }
};