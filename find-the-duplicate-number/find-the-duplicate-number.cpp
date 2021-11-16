class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tort=nums[nums[0]], hare=nums[nums[nums[0]]];
        while(hare!=tort){
            tort=nums[tort];
            hare=nums[nums[hare]];
        }
        hare=nums[0];
        while(hare!=tort){
            tort=nums[tort];
            hare=nums[hare];
        }
        return hare;
    }
};