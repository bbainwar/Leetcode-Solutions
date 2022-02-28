class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        queue<pair<int, int>> st;
        bool ones=false;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    st.push(make_pair(i, j));
                }
                else if(!ones && grid[i][j]==1) ones=true;
            }
        }
        
        if(st.empty() && !ones) return 0;
        
        vector<int> x{-1, 0, 1, 0};
        vector<int> y{0, -1, 0, 1};
        int minutes=0;
        while(!st.empty()){
            minutes++;
            int sz=st.size();
            while(sz--){
                int x_cor=st.front().first, y_cor=st.front().second;
                st.pop();
                for(int i=0; i<4; i++){
                    int xc=x_cor+x[i], yc=y_cor+y[i];
                    if(xc>=0 && yc>=0 && xc<m && yc<n  && grid[xc][yc]==1){
                        st.push(make_pair(xc, yc));
                        grid[xc][yc]=2;
                    }
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        
        return minutes-1;
    }
};