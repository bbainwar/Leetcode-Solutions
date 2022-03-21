class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> right(26, -1), ans;
        int n=s.size();
        for(int i=0; i<n; i++) right[s[i]-'a']=i;
        int ind=0, prev=-1;
        while(ind<n){
            int i=ind;
            int maxm=right[s[i]-'a'];
            while(i<maxm){
                if(right[s[i]-'a']>maxm){
                    maxm=right[s[i]-'a'];
                }
                i++;
            }
            ans.push_back(maxm-prev);
            prev=maxm;
            if(maxm>=n-1) break;
            ind=maxm+1;
        }
        return ans;
    }
};