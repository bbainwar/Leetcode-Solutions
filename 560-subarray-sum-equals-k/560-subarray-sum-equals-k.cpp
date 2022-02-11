class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int, int> umap;
        umap[0]++;
        int ans=0;
        for(int i=0; i<n; i++){
            if(i!=0)
                nums[i]+=nums[i-1];
            if(umap.find(nums[i]-k)!=umap.end()){
                ans+=umap[nums[i]-k];
            }
            umap[nums[i]]++;
        }
        return ans;
    }
};