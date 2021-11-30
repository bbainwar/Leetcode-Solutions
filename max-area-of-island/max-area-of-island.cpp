class Solution {
public:
    int solution(vector<vector<int>> &grid, int sx, int sy){
        if(sx<0 || sx>=grid.size() || sy<0 || sy>=grid[0].size()){
            return 0;
        }
        if(grid[sx][sy]==0 || grid[sx][sy]==-1)
            return 0;
        
        grid[sx][sy]=-1;
        
        vector<int> x={-1, 0, 1, 0};
        vector<int> y={0, -1, 0, 1};
        
        int ans=0;
        for(int i=0; i<4; i++){
            ans+=solution(grid, sx+x[i], sy+y[i]);
        }
        return 1+ans;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxm=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]!=0 && grid[i][j]!=-1){
                    int temp=solution(grid, i, j);
                    maxm=max(maxm, temp);
                    cout<<i<<" "<<j<<" "<<temp<<endl;
                }
            }
        }
        return maxm;
    }
};