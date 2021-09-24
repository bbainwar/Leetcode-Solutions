class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        int a=1, b=1, c=2;
        if(n<3){
            return 1;
        }
        if(n==3){
            return 2;
        }
        for(int i=4; i<=n; i++){
            int temp_c=a+b+c, temp_b=c, temp_a=b;
            c=temp_c;
            b=temp_b;
            a=temp_a;
        }
        return c;
    }
};