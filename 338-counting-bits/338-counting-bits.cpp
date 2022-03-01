class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> nums{0};
        if(n==0) return nums;
        int count=0;
        while(true){
            int sz=nums.size();
            for(int i=0; i<sz; i++){
                nums.push_back(1+nums[i]);
                count++;
                if(count==n) break;
            }
            if(count==n) break;
        }
        return nums;
    }
};