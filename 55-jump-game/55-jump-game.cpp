class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ind=0;
        for(int reach=0; ind<=reach && ind<nums.size(); ind++){
            reach=max(reach, ind+nums[ind]);
        }
        return ind==nums.size();
    }
};