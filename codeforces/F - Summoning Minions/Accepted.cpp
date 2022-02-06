/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 20:16                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 108 ms                                          memory_used: 300 KB                               
*  problem: https://codeforces.com/contest/1354/problem/F
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<unordered_map>
#include<random>
#include<chrono>
#define long long long
using namespace std;
const int N=75;
const int INF=1e9;//should be greater than overall matching cost
int cost[N+2][N+2],ans[N+2];
int hungarian(int n,int m)
{
  vector<int>u(n+1),v(m+1),p(m+1),way(m+1);
  for(int i=1;i<=n;i++)
  {
    p[0]=i;int j0=0;
    vector<int>minv(m+1,INF);
    vector<char>used(m+1,false);
    do
    {
      used[j0]=true;int i0=p[j0],delta=INF,j1;
      for(int j=1;j<=m;j++)
      {
        if(!used[j])
        {
          int cur=cost[i0][j]-u[i0]-v[j];
          if(cur<minv[j])minv[j]=cur,way[j]=j0;
          if(minv[j]<delta)delta=minv[j],j1=j;
        }
      }
      for(int j=0;j<=m;j++)
      {
        if(used[j])u[p[j]]+=delta,v[j]-=delta;
        else minv[j]-=delta;
      }
      j0=j1;
    }while(p[j0]!=0);
    do 
    {
      int j1=way[j0];p[j0]=p[j1];
      j0=j1;
    }while(j0);
  }
  int ret=0;
  for(int i=1;i<=m;i++)ret+=cost[p[i]][i];
  for(int i=1;i<=m;i++)ans[p[i]]=i;
  return ret;
}
int aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>aa[i]>>bb[i];
    for(int i=1;i<=k;i++)
    {
      for(int j=1;j<=n;j++)
        cost[i][j]=-(aa[j]+bb[j]*(i-1));
    }
    for(int i=k+1;i<=n;i++)
    {
      for(int j=1;j<=n;j++)
        cost[i][j]=-(bb[j]*(k-1));
    }
    hungarian(n,n);
    cout<<(n-k)*2+k<<"\n";
    for(int i=1;i<k;i++)cout<<ans[i]<<" ";
    for(int i=k+1;i<=n;i++)cout<<ans[i]<<" "<<-ans[i]<<" ";
    cout<<ans[k]<<endl;
  }
  return 0;
}