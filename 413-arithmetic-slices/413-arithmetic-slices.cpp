class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalSlices=0, n=nums.size();
        if(n<3) return 0;
        int presDiff=nums[1]-nums[0], lSize=0;
        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1]==presDiff){
                lSize++;
                totalSlices+=lSize;
            }
            else{
                presDiff=nums[i]-nums[i-1];
                lSize=0;
            }
        }
        return totalSlices;
    }
};