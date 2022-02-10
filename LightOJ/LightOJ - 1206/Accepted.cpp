/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-01-20 17:56:27                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 20                                         memory_used (MB): 2.8                             
*  problem: https://vjudge.net/problem/LightOJ-1206
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=500,inf=1e9;

bool used[N+2];int mt[N+2];
vector<int>adj[N+2];//only edge from left to right
bool tryKuhn(int v)
{
  if(used[v])return false;used[v]=true;
  for(auto u:adj[v])
  {
    if(mt[u]==-1||tryKuhn(mt[u]))
    {
      mt[u]=v;return true;
    }
  }
  return false;
}
bool usd[N+2];
int solve(int a,int b)
{
  for(int i=1;i<=b;i++)mt[i]=-1;
  for(int i=1;i<=a;i++)usd[i]=false;
  for(int i=1;i<=a;i++)
  {
    for(auto x:adj[i])
    {
      if(mt[x]!=-1)continue;
      mt[x]=i;usd[i]=true;break;
    }
  }
  for(int i=1;i<=a;i++)
  {
    if(usd[i])continue;
    for(int j=1;j<=a;j++)used[j]=false;
    tryKuhn(i);
  }
  int ret=0;
  for(int i=1;i<=b;i++)
  {
    if(mt[i]!=-1)ret++;
  }
  for(int i=1;i<=a;i++)
    adj[i].clear();
  return ret;
}
int aa[N+2],bb[N+2],cc[N+2],dd[N+2],tim[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;string s;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
      cin>>s>>aa[i]>>bb[i]>>cc[i]>>dd[i];
      int hh=(s[0]-'0')*10+(s[1]-'0'),mm=(s[3]-'0')*10+(s[4]-'0');
      tim[i]=hh*60+mm;
    }
    for(int i=1;i<=n;i++)
    {
      for(int j=i+1;j<=n;j++)
      {
        if(tim[i]+abs(cc[i]-aa[i])+abs(dd[i]-bb[i])+abs(aa[j]-cc[i])+abs(bb[j]-dd[i])<tim[j])
          adj[i].push_back(j);
      }
    }
    cout<<"Case "<<++tc<<": "<<n-solve(n,n)<<"\n";//memset(Hun,0,sizeof(Hun));
  }
  return 0;
}