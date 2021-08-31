class Solution {
public:
    vector<vector<int>> ans;
    void solution(vector<int> nums, int index, vector<int> tillNow){
        if(index==nums.size()){return;}
        
        for(int i=index; i<nums.size(); i++){
            tillNow.push_back(nums[i]);
            ans.push_back(tillNow);
            solution(nums, i+1, tillNow);
            tillNow.pop_back();
            while(i<nums.size()-1 && nums[i]==nums[i+1]){i++;}
            
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.push_back({});
        solution(nums, 0, {});
        return ans;
    }
};