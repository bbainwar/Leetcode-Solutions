class Solution {
public:
    int gcd(int a, int b){
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> count;
        int minm=INT_MAX;
        for(int i: deck){
            count[i]++;
        } 
        int hcf = count.begin()->second;
        for(auto itr=count.begin(); itr!=count.end(); itr++){
            hcf=gcd(hcf, itr->second);
        }
        return hcf>1; 
    }
};