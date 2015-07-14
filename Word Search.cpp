/*dfs*/
class Solution {
public:
    bool flag;
    int n,m;
    int go[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
    void dfs(vector<vector<char> > &board,string word,int d,int x,int y){
        if(flag) return;
        if(d>=(int)word.size()){
            flag = true;
            return;
        }
        for(int i=0; i<4; ++i){
            int nx = x + go[i][0];
            int ny = y + go[i][1];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(board[nx][ny]==word[d]) {
                char tmp = board[nx][ny];
                board[nx][ny] = '@';
                dfs(board,word,d+1,nx,ny);
                board[nx][ny] = tmp;
            }
         }
    }
    bool exist(vector<vector<char> > &board, string word) {
        if((int)word.size()==0) return true;
        n = (int)board.size();
        if(n<=0) return false;
        m = (int)board[0].size();
        flag = false;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(board[i][j]==word[0]){
                    char tmp = board[i][j];
                    board[i][j] = '@';
                    dfs(board,word,1,i,j);
                    board[i][j] = tmp;
                }
        return flag;
    }
};
