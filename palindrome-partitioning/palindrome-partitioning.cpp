class Solution {
public:
    vector<vector<string>> ans;
    bool palindrome(string str, int start, int end){
        while(start<=end){
            if(str[start]!=str[end])
                return false;
            start++; end--;
        }
        return true;
    }
    void palPart(string str, int start, vector<string> tillNow){
        if(start>=str.size()){
            ans.push_back(tillNow);
        }
        for(int i=start; i<str.size(); i++){
            if(palindrome(str, start, i)){
                tillNow.push_back(str.substr(start, i-start+1));
                palPart(str, i+1, tillNow);
                tillNow.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        palPart(s, 0, {});
        return ans;
    }
};