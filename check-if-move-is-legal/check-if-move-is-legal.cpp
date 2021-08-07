class Solution {
public:
    bool valid(int row, int col){
        if(row<0 || row>7 || col<0 || col>7)
            return false;
        return true;
    }
    bool checkMove(vector<vector<char>>& board, int row, int col, char color) {
        char oppCol;
        if(color=='W')
            oppCol='B';
        else
            oppCol='W';
        
        if(valid(row-1, col) && board[row-1][col]==oppCol){
            for(int i=row-2; i>=0; i--){
                if(board[i][col]=='.') {break;}
                if(board[i][col]==color)
                    return true;
            }
        }
        
        if(valid(row+1, col) && board[row+1][col]==oppCol){
            for(int i=row+2; i<8; i++){
                if(board[i][col]=='.') {break;}
                if(board[i][col]==color)
                    return true;
            }
        }
        
        if(valid(row, col-1) && board[row][col-1]==oppCol){
            for(int j=col-2; j>=0; j--){
                if(board[row][j]=='.') {break;}
                if(board[row][j]==color)
                    return true;
            }
        }
        
        if(valid(row, col+1) && board[row][col+1]==oppCol){
            for(int j=col+2; j<8; j++){
                if(board[row][j]=='.') {break;}
                if(board[row][j]==color)
                    return true;
            }
        }
        
        if(valid(row-1, col-1) && board[row-1][col-1]==oppCol){
            int x=row-2, y=col-2;
            while(valid(x, y)){
                if(board[x][y]=='.'){break;}
                if(board[x][y]==color){return true;}
                x--; y--;
            }
        }
        
        if(valid(row+1, col-1) && board[row+1][col-1]==oppCol){
            int x=row+2, y=col-2;
            while(valid(x, y)){
                if(board[x][y]=='.'){break;}
                if(board[x][y]==color){return true;}
                x++; y--;
            }
        }
        
        if(valid(row-1, col+1) && board[row-1][col+1]==oppCol){
            int x=row-2, y=col+2;
            while(valid(x, y)){
                if(board[x][y]=='.'){break;}
                if(board[x][y]==color){return true;}
                x--; y++;
            }
        }
        
        if(valid(row+1, col+1) && board[row+1][col+1]==oppCol){
            int x=row+2, y=col+2;
            while(valid(x, y)){
                if(board[x][y]=='.'){break;}
                if(board[x][y]==color){return true;}
                x++; y++;
            }
        }
        
        return false;
    }
};