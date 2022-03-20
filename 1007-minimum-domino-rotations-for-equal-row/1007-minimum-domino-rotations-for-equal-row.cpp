class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        vector<int> count(7, 0);
        for(int i=0; i<n; i++){
            if(tops[i]==bottoms[i]){
                count[tops[i]]++;
            }
            else{
                count[tops[i]]++;
                count[bottoms[i]]++;
            }
        }
        for(int i: count) cout<<i<<" ";
        int poss=0, val=-1;
        for(int i=1; i<7; i++){
            if(count[i]==n){
                val=i;
                poss++;
            }
        }
        if(poss==0){
            return -1;
        }
        else if(poss==1){
            int countTop=0, countBottom=0;
            for(int i=0; i<n; i++){
                if(tops[i]!=val) countTop++;
                if(bottoms[i]!=val) countBottom++;
            }
            return min(countTop, countBottom);
        }
        else{
            int ct=0;
            for(int i=0; i<n; i++){
                if(tops[i]==val) ct++;
            }
            return min(ct, n-ct);
        }
        
    }
};