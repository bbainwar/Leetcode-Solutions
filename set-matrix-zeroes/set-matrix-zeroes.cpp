class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        int m=matrix.size(), n=matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==0){
                    zeroes.push_back(make_pair(i ,j));
                }
            }
        }
        for(int posn=0; posn<zeroes.size(); posn++){
            int x=zeroes[posn].first, y=zeroes[posn].second;
            for(int i=0; i<m; i++){
                matrix[i][y]=0;
            }
            for(int i=0; i<n; i++){
                matrix[x][i]=0;
            }
        }
    }
};