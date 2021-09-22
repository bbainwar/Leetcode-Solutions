class Solution {
public:
    vector<vector<string>> ans;
    
    bool validMove(vector<string> board, int row, int col){
        int dy[]={-1, 0, 1};
        int dx[]={-1, -1, -1};
        for(int i=0; i<3; i++){
            int px=row, py=col;
            while(true){
                px+=dx[i]; py+=dy[i];
            
                if(px<0 || py<0 || px>=board[0].size() || py>=board[0].size()){
                    break;
                }
                if(board[px][py]=='Q'){
                    return false;
                }
            }
        }
        return true;
    }
    
    void placeQueen(vector<string> board, int row){
        int n=board.size();
        if(row>=n){
            ans.push_back(board);
            return;
        }
        for(int i=0; i<n; i++){
            if(validMove(board, row, i)){
                board[row][i]='Q';
                placeQueen(board, row+1);
                board[row][i]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        
        for(int i=0; i<n; i++){s+='.';}
        vector<string> board(n, s);
        
        placeQueen(board, 0);
        
        return ans;
        
    }
};