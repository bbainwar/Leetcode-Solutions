class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        if(target<nums[0])
            return 0;
        if(target>nums[n-1])
            return n;
        int low=0, high=n-1, mid;
        while(low<=high){
            mid=(low+high)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};