class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sl=s.size(), pl=p.size();
        vector<int> ans;
        if(sl<pl) return ans;
        vector<int> cp(26, 0), sp(26, 0);
        for(char c: p){
            cp[c-'a']++;
        }
        
        int left=0, right=pl-1;
        for(int i=left; i<=right; i++){
            sp[s[i]-'a']++;
        }
        
        
        while(right<sl){
            cout<<left<<" ";
            if(sp==cp){
                ans.push_back(left);
            }
            sp[s[left]-'a']--;
            left++; right++;
            if(right>=sl) break;
            sp[s[right]-'a']++;
        }
        return ans;
    }
};