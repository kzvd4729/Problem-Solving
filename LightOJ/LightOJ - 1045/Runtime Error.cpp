/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-11 10:01:57                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1045
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
double arr[1000003];
void logarithm(void)
{
    int i;
    arr[0]=0;
    for(i=1;i<=1000000;i++)
    {
        arr[i]=log(i);
        arr[i]=arr[i]+arr[i-1];
    }
}
int main()
{
    logarithm();
    double ans;
    long long int c,t,n,tc=0,b;
    scanf("%lld",t);
    while(t--)
    {
        scanf("%lld%lld",&n,&b);
        ans=arr[n]/log(b);
        c=(floor(ans)+1);
        printf("Case %lld: %lld\n",++tc,c);
    }
    return 0;
}