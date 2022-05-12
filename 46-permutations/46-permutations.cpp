class Solution {
public:
    vector<vector<int>> ans;
    void sol(vector<int> nums, int start){
        int n=nums.size();
        if(start>=n) return;
        if(start==n-1){
            ans.push_back(nums);
            return;
        }
        for(int i=start; i<n; i++){
            swap(nums[i], nums[start]);
            sol(nums, start+1);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        sol(nums, 0);
        return ans;
    }
};