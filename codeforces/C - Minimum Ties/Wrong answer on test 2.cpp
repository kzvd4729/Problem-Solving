/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 21:21                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1487/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int vs[100+2][100+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    if(n==2)
    {
      cout<<0<<'\n';
      continue;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        vs[i][j]=0;
    }
     for(int d=1; ;d++)
    {
      int f=1;
      for(int i=1;i<=n;i++)
      {
        int u=i,v=i+d;
        v%=n;
        if(v==0)v=n;
         int uu=min(u,v),vv=max(u,v);
         if(vs[uu][vv]!=0){f=0;break;}
                if(uu==u)vs[uu][vv]=1;
        else vs[uu][vv]=-1;
       }
      if(f==0)break;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
        cout<<vs[i][j]<<'\n';
    }
  }
  return 0;
}