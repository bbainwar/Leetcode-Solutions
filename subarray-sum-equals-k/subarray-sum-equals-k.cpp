class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0, n=nums.size();
        unordered_map<int, int> umap;
        vector<int> prefixSum(n, 0);
        prefixSum[0]=nums[0];
        umap[prefixSum[0]]++;
        if(prefixSum[0]==k)
                count++;
            
        for(int i=1; i<n; i++){
            prefixSum[i]=prefixSum[i-1]+nums[i];
            //cout<<prefixSum[i]<<endl;
            if(prefixSum[i]==k)
                count++;
            count+=umap[prefixSum[i]-k];
            umap[prefixSum[i]]++;
        }
        
        return count;
    }
};