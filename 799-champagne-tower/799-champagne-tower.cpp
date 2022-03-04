class Solution {
public:
    double min(double a, double b){
        return (a>b)?b:a;
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> t(105, 0.0);
        vector<vector<double>> A(105, t);
        A[0][0]=(double)poured;
        for(int i=0; i<=query_row; i++){
            for(int j=0; j<=i; j++){
                double q=(A[i][j]-1.0)/2.0;
                if(q>0.0){
                    A[i+1][j]+=q;
                    A[i+1][j+1]+=q;
                }
            }
        }
        return min(1.0, A[query_row][query_glass]);
    }
};