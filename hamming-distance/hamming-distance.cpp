class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance=0;
        while(x!=0 || y!=0){
            //cout<<x<<" "<<y<<endl;
            if(x%2!=y%2){
                distance++;
            }
            x=x>>1; y=y>>1;
        }
        return distance;
    }
};