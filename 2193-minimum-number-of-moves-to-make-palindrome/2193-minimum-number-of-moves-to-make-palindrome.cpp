class Solution {
public:
    void print(vector<int> v){
        for(auto a: v) cout<<a<<" ";
        cout<<endl;
    }
    bool palindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++; j--;
        }
        return true;
    }
    int solution(string s, int left, int right){
        if(left>=right) return 0;
        
        int l=left, r=right;
        
        vector<int> lc(26, -1);
        vector<int> rc(26, -1);
        for(int i=left; i<=right; i++){
            if(lc[s[i]-'a']==-1){
                lc[s[i]-'a']=i;
            }
        }
        for(int i=right; i>=left; i--){
            if(rc[s[i]-'a']==-1 && lc[s[i]-'a']!=i){
                rc[s[i]-'a']=i;
            }
        }
        int minm=2005;
        pair<int, int> minInd;
        for(int i=0; i<26; i++){
            if(lc[i]!=-1 && rc[i]!=-1){
                if(right-rc[i]+lc[i]-left<minm){
                    minm=right-rc[i]+lc[i]-left;
                    minInd=make_pair(lc[i], rc[i]);
                }
            }
        }
        // cout<<minm<<endl;
        // print(lc);
        // print(rc);
        int cost=minInd.first-left+right-minInd.second;
        // swap(s[left], s[minInd.first]);
        for(int i=minInd.first; i>left; i--){
            swap(s[i], s[i-1]);
        }
        // swap(s[right], s[minInd.second]);
        for(int i=minInd.second; i<right; i++){
            swap(s[i], s[i+1]);
        }
        // cout<<s<<endl;
        
        return cost+solution(s, left+1, right-1);
    }
    int minMovesToMakePalindrome(string s) {
        return solution(s, 0, s.size()-1);
    }
};