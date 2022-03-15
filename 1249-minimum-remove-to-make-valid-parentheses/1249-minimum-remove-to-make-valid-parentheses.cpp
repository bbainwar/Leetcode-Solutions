class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int> st;
        vector<int> rem;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    rem.push_back(i);
                }
                else{
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            rem.push_back(st.top());
            st.pop();
        }
        unordered_map<int, int> umap;
        for(int i=0; i<rem.size(); i++){
            umap[rem[i]]=1;
        }
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(umap[i]==1) continue;
            ans+=s[i];
        }
        return ans;
    }
};