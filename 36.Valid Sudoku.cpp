class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //horizon
        for(int i=0; i<9; ++i){
            bool hash[10] = {0};
            for(int j=0; j<9; ++j){
                if(board[i][j]!='.'){
                    if(board[i][j]<'0'||board[i][j]>'9') return false;
                    if(hash[board[i][j]-'0']) return false;
                    hash[board[i][j]-'0'] = true;
                }
            }
        }
        //vertical
        for(int j=0; j<9; ++j){
            bool hash[10] = {0};
            for(int i=0; i<9; ++i){
                if(board[i][j]!='.'){
                    if(board[i][j]<'0'||board[i][j]>'9') return false;
                    if(hash[board[i][j]-'0']) return false;
                    hash[board[i][j]-'0'] = true;
                }
            }
        }
        //block
        for(int ii=0; ii<9; ii+=3)
        for(int jj=0; jj<9; jj+=3){
            bool hash[10] = {0};
            for(int i=0; i<3; ++i)
                for(int j=0; j<3; ++j){
                    if(board[ii+i][jj+j]!='.'){
                        if(board[ii+i][jj+j]<'0'||board[ii+i][jj+j]>'9') return false;
                        if(hash[board[ii+i][jj+j]-'0']) return false;
                        hash[board[ii+i][jj+j]-'0'] = true;
                    }
                }
        }
        return true;
    }
};
