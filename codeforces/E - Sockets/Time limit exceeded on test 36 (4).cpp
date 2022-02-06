/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/18/2018 17:41                        
*  solution_verdict: Time limit exceeded on test 36          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 77600 KB                             
*  problem: https://codeforces.com/contest/732/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int soc[N+2],com[N+2],sck[N+2],c,u;
int n,m,vis[N+2],x,cnt;
map<int,int>mp;
vector<int>vc[N+2];
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
  {
    scanf("%d",&x);
    if(!mp[x])mp[x]=++cnt;
    x=mp[x];
    vc[x].push_back(i);
  }
  for(int i=1;i<=m;i++)
    scanf("%d",&soc[i]);
  for(int p=0;p<=32;p++)
  {
    for(int i=1;i<=m;i++)
    {
      if(vis[i])continue;
      x=mp[soc[i]];
      if(vc[x].size())
      {
        int xx=vc[x].back();
        vc[x].pop_back();
        c++;
        u+=p;
        com[xx]=i;
        sck[i]=p;
        vis[i]=1;
      }
      if(soc[i]==1)vis[i]=1;
      soc[i]=(soc[i]+1)/2;
    }
  }
  printf("%d %d\n",c,u);
  for(int i=1;i<=m;i++)
    printf("%d ",sck[i]);
  printf("\n");
  for(int i=1;i<=n;i++)
    printf("%d ",com[i]);
  printf("\n");
  return 0;
}