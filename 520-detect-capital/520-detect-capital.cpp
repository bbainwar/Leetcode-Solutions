class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        string temp = word;
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if(temp==word)
            return true;
        if(temp[0]+'A'-'a'==word[0] && word.substr(1, n-1)==temp.substr(1, n-1))    
            return true;
        for(int i=0; i<n; i++){
            if(temp[i]+'A'-'a'!=word[i]) return false;
        }
        return true;
    }
};