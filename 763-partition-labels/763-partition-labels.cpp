class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> right(26, -1), ans;
        int n=s.size();
        for(int i=0; i<n; i++) right[s[i]-'a']=i;
        int prev=-1, maxm=0;
        for(int i=0; i<n; i++){
            maxm=max(maxm, right[s[i]-'a']);
            if(i==maxm){
                ans.push_back(maxm-prev);
                prev=maxm;
            }
        }
        return ans;
    }
};