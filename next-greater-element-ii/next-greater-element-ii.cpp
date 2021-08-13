class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){nums.push_back(nums[i]);}
        for(int i=0; i<n; i++){
            for(int j=i+1; j<i+n; j++){
                if(nums[j]>nums[i]){
                    ans[i]=nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};