class Solution {
public:
    void print(vector<vector<int>>& matrix){
        for(auto i: matrix){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int frow=1, fcol=1;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0; i<n; i++){
            if(matrix[i][0]==0){
                fcol=0;
                break;
            }
        }
        for(int i=0; i<m; i++){
            if(matrix[0][i]==0){
                frow=0;
                break;
            }
        }
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        print(matrix);
        for(int i=1; i<n; i++){
            if(matrix[i][0]==0){
                for(int j=0; j<m; j++){
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=1; i<m; i++){
            if(matrix[0][i]==0){
                for(int j=0; j<n; j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(frow==0){
            for(int i=0; i<m; i++){
                matrix[0][i]=0;
            }
        }
        if(fcol==0){
            for(int i=0; i<n; i++){
                matrix[i][0]=0;
            }
        }
    }
};