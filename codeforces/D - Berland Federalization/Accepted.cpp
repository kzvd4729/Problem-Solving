/****************************************************************************************
*  @author: kzvd4729                                         created: May/01/2019 02:20                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1400 KB                              
*  problem: https://codeforces.com/contest/440/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=4e2,inf=1e9;
int n,k,dp[N+2][N+2];
int parent[N+2],mn,sub[N+2];
vector<int>adj[N+2],nex[N+2];
vector<pair<int,int> >ed;
map<pair<int,int>,int>mp;
void dfs(int node,int par)
{
  parent[node]=par;sub[node]=1;
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dfs(x,node);sub[node]+=sub[x];
    nex[node].push_back(x);
  }
  if(nex[node].size()==0)
  {
    dp[node][1]=0;return ;
  }
  int x=nex[node][0];dp[node][1]=1;
  for(int i=2;i<=k;i++)
    dp[node][i]=dp[x][i-1];
  for(int l=1;l<nex[node].size();l++)
  {
    x=nex[node][l];
    for(int i=k;i>=1;i--)
    {
      dp[node][i]++;
      for(int j=1;j<i;j++)
        dp[node][i]=min(dp[node][i],dp[x][j]+dp[node][i-j]);
    }
  }
}
void print(int node,int k,int cut)
{
  //cout<<node<<" ----- "<<k<<endl;
  int sz=nex[node].size();
  if(!sz)return ;
  vector<vector<int> >tmp;
  tmp.resize(sz+2);
  for(int i=0;i<sz;i++)
  {
    tmp[i].resize(k+2);
    for(int j=1;j<=k;j++)
      tmp[i][j]=inf;
  }
   int x=nex[node][0];tmp[0][1]=1;
  for(int i=2;i<=k;i++)
    tmp[0][i]=dp[x][i-1];
  for(int l=1;l<sz;l++)
  {
    x=nex[node][l];
    for(int i=k;i>=1;i--)
    {
      tmp[l][i]=tmp[l-1][i]+1;
      for(int j=1;j<i;j++)
        tmp[l][i]=min(tmp[l][i],dp[x][j]+tmp[l-1][i-j]);
    }
  }
  /*if(node==1){
  for(int i=0;i<sz;i++)
  {
    for(int j=1;j<=10;j++)
    {
      cout<<tmp[i][j]<<" ";
    }
    cout<<endl;
  }}*/
  //if(node==1)cout<<"("<<tmp[0][2]<<endl;
  for(int l=sz-1;l>=1;l--)
  {
    int x=nex[node][l];
    //cout<<l<<" -- "<<k<<endl;
    if(tmp[l-1][k]+1==cut)
    {
      ed.push_back({node,x});cut--;
      //cout<<node<<" **** "<<x<<endl;
      continue;
    }
    //if(node==1)cout<<x<<" -- "<<k<<endl;
    for(int i=1;i<k;i++)
    {
      if(tmp[l-1][k-i]+dp[x][i]==cut)
      {
        //if(node==1)cout<<x<<" -*- "<<l-1<<" "<<k-i<<" "<<tmp[l-1][k-i]<<endl;
        print(x,i,dp[x][i]);k-=i;cut-=dp[x][i];
        break;
      }
    }
  }
  if(k==1)
  {
    ed.push_back({node,nex[node][0]});cut--;
    //cout<<node<<" *** "<<nex[node][0]<<endl;
  }
  else print(nex[node][0],k-1,dp[nex[node][0]][k-1]);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=1;i<n;i++)
  {
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    mp[{u,v}]=mp[{v,u}]=i;
  }
  for(int i=1;i<=n;i++)
    for(int j=1;j<=k;j++)
      dp[i][j]=inf;
  dfs(1,-1);mn=dp[1][k];int rt=1;
  for(int i=2;i<=n;i++)
  {
    if(dp[i][k]+1<mn)
      mn=dp[i][k]+1,rt=i;
  }
  /*for(auto x:nex[1])
    cout<<x<<" ";
  cout<<endl;*/
  if(rt!=1)ed.push_back({rt,parent[rt]});
  print(rt,k,dp[rt][k]);cout<<mn<<endl;
  for(auto x:ed)cout<<mp[{x.first,x.second}]<<" ";
    cout<<endl;
  return 0;
}