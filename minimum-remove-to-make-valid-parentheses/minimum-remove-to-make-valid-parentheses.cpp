class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> removeRight;
        stack<int> leftParen;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                leftParen.push(i);
            }
            else if(s[i]==')'){
                if(leftParen.empty()){
                    removeRight.push_back(i);
                }
                else{
                    leftParen.pop();
                }
            }
        }
        unordered_map<int, int> umap;
        for(int i: removeRight){
            umap[i]=1;
        }
        while(!leftParen.empty()){
            umap[leftParen.top()]=1;
            leftParen.pop();
        }
        
        string ans="";
        for(int i=0; i<s.size(); i++){
            if(umap[i]==1){
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};