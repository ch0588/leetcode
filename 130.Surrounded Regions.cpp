/*
从最外围四个边向内fill，能够fill到的O点就不会被包围，否则会被包围。
*/
class Solution {
public:
    int go[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
    void BFS(vector<vector<char>>& board,pair<int,int>start,int n,int m){
        queue<pair<int,int>>Q;
        board[start.first][start.second] = '.'; //.means can't surrond
        Q.push(start);
        pair<int,int>now,next;
        while(!Q.empty()){
            now = Q.front();    Q.pop();
            for(int i=0; i<4; ++i){
                next.first = now.first + go[i][0];
                next.second = now.second + go[i][1];
                if( next.first>=0&&next.first<n && next.second>=0&&next.second<m && board[next.first][next.second]=='O'){
                    Q.push(next);
                    board[next.first][next.second] = '.';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n==0) return;
        int m = board[0].size();
        if(m==0) return;
        
        for(int i=0; i<n; ++i){ //fill left and right edge
            if(board[i][0]=='O') BFS(board,make_pair(i,0),n,m);
            if(board[i][m-1]=='O') BFS(board,make_pair(i,m-1),n,m);
        }
        for(int i=0; i<m; ++i){ //fill top and bottom edge
            if(board[0][i]=='O') BFS(board,make_pair(0,i),n,m);
            if(board[n-1][i]=='O') BFS(board,make_pair(n-1,i),n,m);
        }
        
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(board[i][j] == '.') board[i][j] = 'O';
                else board[i][j] = 'X';
    }
};