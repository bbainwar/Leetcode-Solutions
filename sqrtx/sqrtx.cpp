class Solution {
public:
    int mySqrt(int x) {
        for(int i=46340; i>=0; i--){
            if(i*i<=x)
                return i;
        }
        return -1;
    }
};