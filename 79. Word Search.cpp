// Time Complexity: O(m * n * 4 ^ p), where m is board width, n is board height, p is word length
// Space Complexity: O(m * n + p)

/*dfs*/
class Solution {
public:
    int n, m;
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<char> > &board, string word, int d, int x, int y) {
        if (d >= (int)word.size()) {
            return true;
        }
        for (int i = 0; i < 4; ++i) {
            int nx = x + go[i][0];
            int ny = y + go[i][1];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == word[d]) {
                char tmp = board[nx][ny];
                board[nx][ny] = '@';
                if ( dfs(board, word, d + 1, nx, ny) ) return true;
                board[nx][ny] = tmp;
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        if ((int)word.size() == 0) return true;
        n = (int)board.size();
        if (n <= 0) return false;
        m = (int)board[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (board[i][j] == word[0]) {
                    char tmp = board[i][j];
                    board[i][j] = '@';
                    if ( dfs(board, word, 1, i, j) ) return true;
                    board[i][j] = tmp;
                }
        return false;
    }
};
