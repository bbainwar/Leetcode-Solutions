class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n1=nums1.size(), n2=nums2.size(), n3=nums3.size(), n4=nums4.size();
        int ans=0;
        unordered_map<int, int> umap34;
        for(int i=0; i<n3; i++){
            for(int j=0; j<n4; j++){
                int temp=nums3[i]+nums4[j];
                umap34[temp]++;
            }
        }
        
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                int temp=(nums1[i]+nums2[j]);
                ans+=umap34[-temp];
            }
        }
        return ans;
    }
};