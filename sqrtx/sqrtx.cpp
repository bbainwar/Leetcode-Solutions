class Solution {
public:
    int mySqrt(int x) {
        if(x==0){return 0;}
        double low=0, high=x;
        double mid=(low+high)/2;
        int count=10000;
        while(count--){
            mid=(low+high)/2;
            low=mid; high=x/mid;
        }
        return (int)mid;
    }
};