/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/07/2018 18:01                        
*  solution_verdict: Wrong answer on test 9                  language: GNU C++14                               
*  run_time: 358 ms                                          memory_used: 25200 KB                             
*  problem: https://codeforces.com/contest/547/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int inf=1e9;
const int N=5e5;
int vis[N+2],n,arr[N+2];
int sz,ans,cnt[N+2],q;
vector<int>pr[N+2];
void seive(void)
{
  for(int i=2;i<=N;i++)
  {
    if(vis[i])continue;
    for(int j=i;j<=N;j+=i)
    {
      pr[j].push_back(i);
      vis[j]=i;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   seive();
  cin>>n>>q;
  for(int i=1;i<=n;i++)
    cin>>arr[i];
  memset(vis,-1,sizeof(vis));
  while(q--)
  {
    int x;cin>>x;
    int xx=arr[x];
    int z=pr[xx].size();
    if(vis[x]==-1)
    {
      vis[x]=1;ans+=sz;
      for(int i=1;i<(1<<z);i++)
      {
        int he=1,c=0;
        for(int j=0;j<z;j++)
        {
          if(i&(1<<j))
          {
            c++;
            he*=pr[xx][j];
          }
        }
        if(c%2)
          ans-=cnt[he];
        else ans+=cnt[he];
      }
      sz++;
      for(int i=1;i<(1<<z);i++)
      {
        int he=1;
        for(int j=0;j<z;j++)
          if(i&(1<<j))
            he*=pr[xx][j];
        cnt[he]++;
      }
    }
    else
    {
      vis[x]=-1;sz--;ans-=sz;
      for(int i=1;i<(1<<z);i++)
      {
        int he=1;
        for(int j=0;j<z;j++)
          if(i&(1<<j))
            he*=pr[xx][j];
        cnt[he]--;
      }
      for(int i=1;i<(1<<z);i++)
      {
        int he=1,c=0;
        for(int j=0;j<z;j++)
        {
          if(i&(1<<j))
          {
            c++;
            he*=pr[xx][j];
          }
        }
        if(c%2)
          ans+=cnt[he];
        else ans-=cnt[he];
      }
    }
    cout<<ans<<"\n";
  }
  return 0;
}