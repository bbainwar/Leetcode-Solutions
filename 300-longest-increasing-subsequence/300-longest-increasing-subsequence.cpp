class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr;
        for(int i: nums){
            if(arr.empty()==true){
                arr.push_back(i);
            }
            else if(arr[arr.size()-1]<i){
                arr.push_back(i);
            }
            else{
                int ind=lower_bound(arr.begin(), arr.end(), i)-arr.begin();
                arr[ind]=i;
            }
        }
        return arr.size();
    }
};