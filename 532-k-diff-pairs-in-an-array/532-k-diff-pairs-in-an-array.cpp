class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i: nums) umap[i]++;
        int ans=0;
        for(auto i: umap){
            if((k==0 && i.second>1) || (k!=0 && umap.find(i.first+k)!=umap.end()))
                ans++;
        }
        return ans;
    }
};