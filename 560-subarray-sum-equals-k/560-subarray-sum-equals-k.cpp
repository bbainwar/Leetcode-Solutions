class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1; i<n; i++) nums[i]+=nums[i-1];
        unordered_map<int, int> umap;
        umap[0]++;
        int ans=0;
        for(int i=0; i<n; i++){
            if(umap.find(nums[i]-k)!=umap.end()){
                ans+=umap[nums[i]-k];
            }
            umap[nums[i]]++;
        }
        return ans;
    }
};