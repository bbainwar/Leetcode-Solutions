class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int totalSlices=0, n=nums.size();
        if(n<3) return 0;
        int presDiff=nums[1]-nums[0], lSize=2;
        for(int i=2; i<n; i++){
            if(nums[i]-nums[i-1]==presDiff){
                lSize++;
            }
            else{
                if(lSize>=3)
                    totalSlices+=((lSize-1)*(lSize-2))/2;
        
                presDiff=nums[i]-nums[i-1];
                lSize=2;
            }
        }
        if(lSize>=3)
            totalSlices+=((lSize-1)*(lSize-2))/2;
        
        return totalSlices;
    }
};