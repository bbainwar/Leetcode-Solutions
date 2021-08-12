class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxm=INT_MIN, sec_maxm=INT_MIN, ind;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>maxm){
                maxm=nums[i];
                ind=i;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>sec_maxm && i!=ind){
                sec_maxm=nums[i];
            }
        }
        return (maxm-1)*(sec_maxm-1);
    }
};