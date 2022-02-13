class Solution {
public:
    void solution(vector<int>& nums, vector<int> prev, int ind, vector<vector<int>>& ans){
        if(ind==nums.size()){return;}
        
        for(int i=ind; i<nums.size(); i++){
            prev.push_back(nums[i]);
            ans.push_back(prev);
            solution(nums, prev, i+1, ans);
            prev.pop_back();
        }
        
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        solution(nums, {}, 0, ans);
        return ans;
    }
};