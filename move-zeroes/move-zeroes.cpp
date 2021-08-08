class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count0=0;
        for(int i: nums){count0++;}
        int j=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){continue;}
            else{
                nums[j]=nums[i];
                j++;
            }
        }
        for(j; j<nums.size(); j++){
            nums[j]=0;
        }
    }
};