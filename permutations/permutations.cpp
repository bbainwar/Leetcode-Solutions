class Solution {
public:
    vector<vector<int>> ans;
    void solution(vector<int> nums, int s, int e){
        if(s==e){
            ans.push_back(nums);
            return;
        }
        for(int i=s; i<=e; i++){
            swap(nums[s], nums[i]);
            solution(nums, s+1, e);
            swap(nums[s], nums[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solution(nums, 0, nums.size()-1);
        return ans;
    }
};