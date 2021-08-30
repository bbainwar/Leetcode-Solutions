class Solution {
public:
    vector<vector<int>> ans;
    void solution(vector<int> nums, int index, vector<int> tillNow){
        if(index==nums.size()){
            ans.push_back(tillNow);
            return;
        }
        solution(nums, index+1, tillNow);
        tillNow.push_back(nums[index]);
        solution(nums, index+1, tillNow);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solution(nums, 0, {});
        return ans;
    }
};