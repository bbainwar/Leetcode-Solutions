class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        for(int i=0; i<=ceil(log2(n)); i++){
            n=(n^(1<<i));
        }
        return n;
    }
};