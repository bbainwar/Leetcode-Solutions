class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while(getline(ss, tmp, '/')){
            if(tmp=="" || tmp==".") continue;
            else if(tmp!="..") stk.push_back(tmp);
            else if(stk.empty()==false) stk.pop_back();
        }
        string ans="";
        for(string str: stk){
            ans+="/"+str;
        }
        return ans.empty()?"/":ans;
    }
};