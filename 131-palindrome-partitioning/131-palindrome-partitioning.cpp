class Solution {
public:
    vector<vector<string>> ans;
    bool checkPalin(string str, int start, int end){
        while(start<end){
            if(str[start]!=str[end]){
                return false;
            }
            start++; end--;
        }
        return true;
    }
    void print(vector<string> arr){
        for(auto s: arr)
            cout<<s<<" ";
        cout<<"\n";
    }
    
    void generate(string str, int start, vector<string> tillNow){
        if(start>=str.size()){
            // print(tillNow);
            ans.push_back(tillNow);
        }
        int sz=start;
        while(true){
            if(sz<str.size()){
                if(checkPalin(str, start, sz)){
                    tillNow.push_back(str.substr(start, sz-start+1));
                    generate(str, sz+1, tillNow);
                    tillNow.pop_back();
                }
                sz++;
            }
            else{
                break;
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        generate(s, 0, {});
        return ans;
    }
};