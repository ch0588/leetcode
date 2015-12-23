/*
bast on two assumption；
If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
If the total number of gas is bigger than the total number of cost. There must be a solution.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int j = -1;
        for (int i = 0, sum = 0; i < gas.size(); ++i) {
            sum += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (sum < 0) {
                j = i;
                sum = 0; 
            }
        }
        return total >= 0 ? j + 1 : -1;
    }
};  

/*
convert to circular array max sub
这里有两个假设的证明
http://www.cnblogs.com/felixfang/p/3814463.html

*/
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;
typedef long long LL;
const int N = 50005;

int a[N];

LL Work(int a[], int n)
{
    LL ans = 0;
    LL tmp = 0;
    for(int i=0; i<n; i++)
    {
        if(tmp < 0) tmp = a[i];
        else tmp += a[i];
        ans = max(ans, tmp);
    }
    return ans;
}

int main()
{
    int n;
    while(scanf("%d", &n)!=EOF)
    {
        LL ans = 0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            ans += a[i];
        }
        LL ans1 = Work(a, n);
        for(int i=0; i<n; i++)
            a[i] = -a[i];
        LL ans2 = Work(a, n);
        ans = max(ans + ans2, ans1);
        printf("%I64d\n", ans);
    }
    return 0;
}
