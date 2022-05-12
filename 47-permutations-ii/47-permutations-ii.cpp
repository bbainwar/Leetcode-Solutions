class Solution {
public:
    set<vector<int>> ans;
    void sol(vector<int> nums, int start){
        int n=nums.size();
        if(start>=n) return;
        if(start==n-1){
            ans.insert(nums);
            return;
        }
        for(int i=start; i<n; i++){
            swap(nums[i], nums[start]);
            sol(nums, start+1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sol(nums, 0);
        vector<vector<int>> ans2(ans.begin(), ans.end());
        return ans2;
    }
};