/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/15/2021 21:30                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 77 ms                                           memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1487/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=1e9+7;
 int vs[100+2][100+2],sc[100+2];
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
    for(int i=1;i<=n;i++)sc[i]=0;
    for(int d=1; ;d++)
    {
      int f=1;vector<pair<int,int> >bf;
      for(int i=1;i<=n;i++)
      {
        int u=i,v=i+d;
        v%=n;
        if(v==0)v=n;
         int uu=min(u,v),vv=max(u,v);
         if(vs[uu][vv]!=0){f=0;break;}
        bf.push_back({uu,vv});
         if(uu==u)vs[uu][vv]=1;
        else vs[uu][vv]=-1;
       }
      if(f==0)
      {
        for(auto x:bf)vs[x.first][x.second]=0;
        break;
      }
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(vs[i][j]==1)sc[i]+=3;
        else if(vs[i][j]==-1)sc[j]+=3;
        else sc[i]++,sc[j]++;
      }
    }
    //for(int i=1;i<=n;i++)cout<<sc[i]<<" ";cout<<endl;
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
        cout<<vs[i][j]<<'\n';
    }
  }
  return 0;
}