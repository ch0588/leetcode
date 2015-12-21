class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int go[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };
        int n = board.size();
        if(n==0) return;
        int m = board[0].size();
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                int ln = 0; //live neighbors num
                for(int k=0; k<8; ++k){
                    int x = i+go[k][0];
                    int y = j+go[k][1];
                    if(x<0||x>=n || y<0||y>=m) continue;
                    if(board[x][y]==1 || board[x][y]==3) ln++;
                }
                if(board[i][j]==1 && (ln<2||ln>3)) board[i][j]=3; //3: live->dead
                if(board[i][j]==0 && ln==3) board[i][j]=4; //4: dead->vlive
            }
         for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j){
                if(board[i][j]==3) board[i][j] = 0;
                if(board[i][j]==4) board[i][j] = 1;
            }
    }
};