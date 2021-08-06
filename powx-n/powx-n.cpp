class Solution {
public:
    double power(double x, long long n){
        if(n==0)
            return 1;
        if(n%2==1){
            return x*power(x, n-1);
        }
        else{
            double temp=power(x, n/2);
            return temp*temp;
        }
    }
    double myPow(double x, int num) {
        int flag=0;
        long long n=num;
        if(n<0){n=-n; flag=1;}
        if(flag==1){
            return 1/power(x, n);
        }
        return power(x, n);
    }
};