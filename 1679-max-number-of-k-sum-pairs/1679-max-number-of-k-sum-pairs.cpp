class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans=0;
        unordered_map<int, int> umap;
        for(int i: nums){
            if(umap[k-i]!=0){
                umap[k-i]--;
                ans++;
            }
            else{
                umap[i]++;
            }
        }
        return ans;
    }
};