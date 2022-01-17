class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> umap;
        unordered_map<string, char> umap2;
        
        vector<string> v;
        int left=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]==' '){
                v.push_back(s.substr(left, i-left));
                left=i+1;
            }
        }
        v.push_back(s.substr(left, s.size()-left));
        if(v.size()!=pattern.size()) return false;
        // for(auto c: v ) cout<<c<<" ";
        for(int i=0; i<v.size(); i++){
            if(umap2.find(v[i])==umap2.end()){
                umap2[v[i]]=pattern[i];
                // cout<<v[i]<<pattern[i]<<endl;
            }
            else if(umap2[v[i]]!=pattern[i]){
                // cout<<umap[pattern[i]]<<" "<<v[i];
                return false;
            }
            if(umap.find(pattern[i])==umap.end()){
                umap[pattern[i]]=v[i];
                // cout<<v[i]<<pattern[i]<<endl;
            }
            else if(umap[pattern[i]]!=v[i]){
                // cout<<umap[pattern[i]]<<" "<<v[i];
                return false;
            }
        }
        return true;
    }
};