class Solution {
public:
    set<vector<int>> ans;
    void solution(vector<int> nums, int index, vector<int> tillNow){
        if(index==nums.size()){
            sort(tillNow.begin(), tillNow.end());
            ans.insert(tillNow);
            return;
        }
        solution(nums, index+1, tillNow);
        tillNow.push_back(nums[index]);
        solution(nums, index+1, tillNow);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        solution(nums, 0, {});
        vector<vector<int>> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};