/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/17/2019 19:21                        
*  solution_verdict: Memory limit exceeded on test 11        language: GNU C++14                               
*  run_time: 1028 ms                                         memory_used: 262100 KB                            
*  problem: https://codeforces.com/contest/117/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
vector<int>adj[N+2];
vector<pair<int,int> >bk;
int vis[5000+2],lev[N+2],prnt[5000+2];
void dfs(int node,int par,int lv)
{
  lev[node]=lv;prnt[node]=par;
  vis[node]=1;
  for(auto x:adj[node])
  {
    if(vis[x])bk.push_back({node,x});
    else dfs(x,node,lv+1);
  }
}
int main()
{
  //freopen("inp.txt","r",stdin);
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;
  for(int i=1;i<=n;i++)adj[i].clear();
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;
    for(int j=1;j<=n;j++)
      if(s[j-1]=='1')adj[i].push_back(j);
  }
  //cout<<"here"<<endl;
  int mn=n+1,u,v;vector<int>pr;
  for(int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    bk.clear();dfs(i,-1,1);
    for(auto x:bk)
    {
      int df=lev[x.first]-lev[x.second];
      if(df>0&&df<mn)
      {
        int f=0;u=x.first,v=x.second;vector<int>tmp;
        while(true)
        {
          if(u==-1){f=1;break;}
          tmp.push_back(u);if(u==v)break;
          u=prnt[u];
        }
        if(!f)mn=df,pr=tmp;
      }
    }
  }
  if(mn>2)cout<<-1<<endl,exit(0);
  reverse(pr.begin(),pr.end());
  for(auto x:pr)
    cout<<x<<" ";
  cout<<endl;
  return 0;
}