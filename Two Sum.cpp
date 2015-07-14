#include<stdio.h>
#include<string>
#include<string.h>
#include<stack>
#include<algorithm>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

//Have a bug, x+x==target
vector<int> twoSum(vector<int> &numbers, int target) {
    map<int,int>H;
    H.clear();
    int n = (int)numbers.size();

    vector<int>ans;
    for(int i=0; i<n; ++i) {
        H[ numbers[i] ] = i+1;
    }
    for(int i=0; i<n; ++i) {
        if( H.find( target-numbers[i] )!=H.end() ) {
            int x = i+1;
            int y = H[ target-numbers[i] ];
            if(x==y) continue;
            if(x>y) swap(x,y);
            ans.clear();
            ans.push_back(x);
            ans.push_back(y);
            return ans;
        }
    }
    return ans;
}
int main() {
    freopen("in.cpp","r",stdin);
    int n;
    while(~scanf("%d",&n)) {
        vector<int>numbers,ans;
        for(int i=0; i<n; ++i) {
            int x;
            scanf("%d",&x);
            numbers.push_back(x);
        }
        int target;
        scanf("%d",&target);
        ans = twoSum(numbers,target);
        printf("%d %d\n",ans[0],ans[1]);
    }
    return 0;
}
