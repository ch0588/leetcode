#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iostream>
#include<string>
using namespace std;
void rotate(vector<vector<int> >& matrix) {
        int n = (int)matrix.size();
        for(int i=0; i<n/2; ++i){
            for(int j=i; j<n-i-1; ++j){
                int t = matrix[i][j];
                int x=i,y=j;
                for(int k=0; k<3; ++k){
                    int nx = n-y-1,ny = x;
                    matrix[x][y] = matrix[nx][ny];
                    printf("%d %d   %d %d\n",x,y,nx,ny);
                    x = nx; y = ny;
                     for(int ii=0; ii<n; ++ii,printf("\n"))
                    for(int jj=0; jj<n; ++jj)
                        printf("%d",matrix[ii][jj]);
                    printf("\n\n");
                }

                matrix[x][y] = t;
            }
        }
    }
int main() {
    //freopen("1.out","w",stdout);
    //    ["","","","","","","","",""]
    vector<vector<int> >a;
    vector<int>t;
    t.push_back(1);
    t.push_back(2);
    a.push_back(t);
    t.clear();
    t.push_back(3);
    t.push_back(4);
    a.push_back(t);
    rotate(a);
    return 0;
}

