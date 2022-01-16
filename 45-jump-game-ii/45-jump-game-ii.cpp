class Solution {
public:
    int jump(vector<int>& nums) {
        int end=0, maxFar=0, jumps=0;
        for(int i=0; i<nums.size(); i++){
            if(end>=nums.size()-1) break;
            maxFar=max(maxFar, nums[i]+i);
            if(i==end){
                jumps++;
                end=maxFar;
            }
        }
        return jumps;
    }
};