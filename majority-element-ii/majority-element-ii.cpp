class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1, num2=-1;
        int c1=0, c2=0;
        for(int i=0; i<nums.size(); i++){
            if(num1==nums[i]){
                c1++;
            }
            else if(num2==nums[i]){
                c2++;
            }
            else if(c1==0){
                num1=nums[i];
                c1=1;
            }
            else if(c2==0){
                num2=nums[i];
                c2=1;
            }
            
            else{
                c1--;
                c2--;
            }
        }
        int ct1=0, ct2=0;
        for(int i: nums){
            if(i==num1){ct1++;}else if(i==num2){ct2++;}
        }
        int n=nums.size()/3;
        if(ct1>n && ct2>n){
            return {num1, num2};
        }
        if(ct1>n){return {num1};}
        if(ct2>n){return {num2};}
        return {};
    }
};