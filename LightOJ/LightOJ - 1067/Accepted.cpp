/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-14 19:47:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 116                                        memory_used (MB): 9.5                             
*  problem: https://vjudge.net/problem/LightOJ-1067
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define long long long int
#define m 1000003
long t,n,k,f[1000006],x,tc=0;
void factorial(void)
{
    f[0]=1;
    for(long i=1;i<=1000000;i++)
    {
        f[i]=(i*f[i-1])%m;
    }
}
long bigmod(long b,long p)
{
    if(p==0)return 1;
    else if(p%2==0)
    {
        long z=(bigmod(b,p/2))%m;
        return (z*z)%m;
    }
    else return (b*bigmod(b,p-1))%m;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial();
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        x=(f[k]*f[n-k])%m;
        cout<<"Case "<<++tc<<": "<<(f[n]*bigmod(x,m-2))%m<<endl;
    }
    return 0;
}