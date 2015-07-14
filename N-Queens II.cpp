#include<stdio.h>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;
    int lie[100],zhu[100],fu[100];
    int ans;
    int path[100];
    void dfs(int d,int n){
        if(d>n){
            ans++;
            return;
        }
        for(int i=1; i<=n; ++i){
            if(lie[i]==false && zhu[i-d+50]==false && fu[i+d]==false){
                lie[i] = zhu[i-d+50] = fu[i+d] = true;
                path[d] = i;
                dfs(d+1,n);
                lie[i] = zhu[i-d+50] = fu[i+d] = false;
            }
        }
    }
    int totalNQueens(int n) {
        memset(lie,false,sizeof(lie));
        memset(fu,false,sizeof(fu));
        memset(zhu,false,sizeof(zhu));
        ans = 0;
        dfs(1,n);
        return ans;
    }
int main() {
    freopen("in.cpp","r",stdin);
    for(int i=2; i<=10; ++i)
        printf("i=%d %d\n",i,totalNQueens(i));

    return 0;
}
