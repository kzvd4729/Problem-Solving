/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/05/2017 20:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/615/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,vis[103],x,z;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>m;
    while(n--)
    {
        cin>>x;
        while(x--)
        {
            cin>>z;
            vis[z]=1;
        }
    }
    for(long i=1;i<=m;i++)
    {
        if(vis[i]==0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
      return 0;
}