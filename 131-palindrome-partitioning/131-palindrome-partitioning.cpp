class Solution {
public:
    bool isPalin(string str, int start, int end){
        while(start<=end){
            if(str[start]!=str[end])
                return false;
            start++; end--;
        }
        return true;
    }

    vector<vector<string>> ans;
    void palPart(string str, int start, vector<string> tillNow){
        if(start>=str.size()){
            ans.push_back(tillNow);
            return;
        }

        for(int i=start; i<str.size(); i++){
            if(isPalin(str, start, i)==true){
                tillNow.push_back(str.substr(start, i-start+1));
                palPart(str, i+1, tillNow);
                tillNow.pop_back();
            }
        }

    }


    vector<vector<string>> partition(string s) {
        vector<string> tillNow;
        palPart(s, 0, tillNow);
        return ans;
    }
};