#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;
vector<vector<char> >src;
void add(string s) {
    vector<char>t;
    for(int i=0; i<s.size(); ++i) t.push_back(s[i]);
    src.push_back(t);
}
    bool row[9][10],col[9][10],bl[3][3][10];

    bool dfs(vector<vector<char> >&board,int xx,int yy) {
        //printf("xx=%d yy=%d\n",xx,yy);
        if(xx>8) {
            return true;
        }
        if(board[xx][yy]>='1' && board[xx][yy]<='9') return dfs(board,yy>=8?xx+1:xx,yy>=8?0:yy+1);

        for(int k=1; k<10; ++k) {
            if(!row[xx][k]&&!col[yy][k]&&!bl[xx/3][yy/3][k]) {
                board[xx][yy] = k + '0';
                row[xx][k]=col[yy][k]=bl[xx/3][yy/3][k]=true;
                if( dfs(board,yy>=8?xx+1:xx,yy>=8?0:yy+1) ) return true;
                row[xx][k]=col[yy][k]=bl[xx/3][yy/3][k]=false;
                board[xx][yy] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char> >& board) {
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(bl,false,sizeof(bl));
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j) {
                if(board[i][j]>='1'&&board[i][j]<='9') {
                    int x = board[i][j]-'0';
                    row[i][x] = true;
                    col[j][x] = true;
                    bl[i/3][j/3][x] = true;
                }
            }
        dfs(board,0,0);
        for(int i=0; i<9; ++i,printf("\n"))
            for(int j=0; j<9; ++j) printf("%c",board[i][j]);
        printf("\n\n");
    }
int main() {
    //freopen("1.out","w",stdout);
//    ["","","","","","","","",""]
    add("...2...63");
    add("3....54.1");
    add("..1..398.");
    add(".......9.");
    add("...538...");
    add(".3.......");
    add(".263..5..");
    add("5.37....8");
    add("47...1...");

    for(int i=0; i<src.size(); ++i,printf("\n"))
        for(int j=0; j<src[i].size(); ++j) printf("%c",src[i][j]);

    solveSudoku(src);
    return 0;
}

//5 2 4 3 1
//5 3 1 2 4

//[2,3,1,3,3]
//[2,3,3,1,3]
