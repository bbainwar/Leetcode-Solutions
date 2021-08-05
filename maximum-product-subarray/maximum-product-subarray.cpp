class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxm(n, 0);
        vector<int> minm(n, 0);
        maxm[0]=nums[0]; minm[0]=nums[0];
        int maxmProd=nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]==0){
                minm[i]=0;
                maxm[i]=0;
            }
            else{
                minm[i]=min(nums[i], min(nums[i]*minm[i-1], nums[i]*maxm[i-1]));
                maxm[i]=max(nums[i], max(nums[i]*minm[i-1], nums[i]*maxm[i-1]));
            }
            maxmProd=max(maxmProd, maxm[i]);
        }
        return maxmProd;
    }
};