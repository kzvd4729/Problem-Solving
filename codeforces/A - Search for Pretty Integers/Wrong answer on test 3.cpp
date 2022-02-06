/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/16/2017 12:17                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/870/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long vis[12];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long n,m,mn1=10,mn2=10,x;
    cin>>n>>m;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        mn1=min(x,mn1);
        vis[x]=1;
    }
    for(long i=1;i<=m;i++)
    {
        cin>>x;
        vis[x]++;
        mn2=min(mn2,x);
    }
    for(long i=1;i<=9;i++)
    {
        if(vis[i]>1)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<mn1<<mn2<<endl;
     return 0;
}