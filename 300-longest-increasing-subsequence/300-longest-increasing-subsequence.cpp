class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for(int i: nums){
            if(ans.empty() || ans[ans.size()-1]<i){
                ans.push_back(i);
            }
            else{
                int ind=lower_bound(ans.begin(), ans.end(), i)-ans.begin();
                ans[ind]=i;
            }
        }
        return ans.size();
    }
};