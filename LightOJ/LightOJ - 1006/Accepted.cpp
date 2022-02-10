/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-05-08 17:04:41                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 32                                         memory_used (MB): 2.4                             
*  problem: https://vjudge.net/problem/LightOJ-1006
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a, b, c, d, e, f;
int dp[10008];
int fn(int n) 
{
    if(dp[n]!=-1)return dp[n];
    if(n==0)return a;
    if(n==1)return b;
    if(n==2)return c;
    if(n==3)return d;
    if(n==4)return e;
    if(n==5)return f;
    int x1=fn(n-1)%10000007;
    int x2=fn(n-2)%10000007;
    int x3=fn(n-3)%10000007;
    int x4=fn(n-4)%10000007;
    int x5=fn(n-5)%10000007;
    int x6=fn(n-6)%10000007;
    return dp[n]=(x1+x2+x3+x4+x5+x6)%10000007;
}
int main() 
{
    int n,tc=0,t;
    cin>>t;
    while(t--)
    {
        memset(dp,-1,sizeof(dp));
        cin>>a>>b>>c>>d>>e>>f>>n;
        cout<<"Case "<<++tc<<": "<<fn(n)%10000007<<endl;
    }
    return 0;
}
/*
5
0 1 2 3 4 5 20
3 2 1 5 0 1 9
4 12 9 4 5 6 15
9 8 7 6 5 4 3
3 4 3 2 54 5 4
*/