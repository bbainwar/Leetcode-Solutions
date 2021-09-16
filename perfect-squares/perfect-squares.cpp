class Solution {
public:
    bool perfect(int t){
        double x = sqrt(t);
        int y = x;
        if(x==y){return true;}
        return false;
    }
    int numSquares(int n) {
        if(perfect(n)){
            return 1;
        }
    
        for(int i=1; i*i<=n; i++){
            if(perfect(n-i*i)){
                return 2;
            }
        }
        
        while(n%4==0){
            n=n/4;
        }
        if((n-7)%8==0){
            return 4;
        }

        return 3;
    }
};