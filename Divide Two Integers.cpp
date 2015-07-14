#include<stdio.h>
//int range[-2147483648,2147483647]
int divide(int dividend, int divisor)
{
    typedef long long ll;
    ll a = (ll)dividend;
    ll b = (ll)divisor;
    int MAX_INT = 2147483647;
    if(b==0LL) return MAX_INT;
    ll t = a / b;
    if(t+1LL<-(ll)(MAX_INT) || t>(ll)MAX_INT) return MAX_INT;
    return (int)t;
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    printf("%d\n",divide(a,b));
    return 0;
}
