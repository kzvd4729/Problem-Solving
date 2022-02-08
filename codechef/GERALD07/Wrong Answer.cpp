/****************************************************************************************
*  @author: kzvd4729                                         created: 25-09-2019 02:53:26                      
*  solution_verdict: Wrong Answer                            language: C++14                                   
*  run_time: 0.08 sec                                        memory_used: 22.7M                                
*  problem: https://www.codechef.com/problems/GERALD07
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int par[N+2],sq,com,ans[N+2],vis[N+2],vis2[N+2];
vector<pair<int,int> >ed;
vector<int>adj[N+2];
bool cmp(vector<int>&a,vector<int>&b)
{
  if(a[0]/sq==b[0]/sq)return a[1]<b[1];
  return a[0]<b[0];
}
int get(int x)
{
  if(x==par[x])return x;
  return par[x]=get(par[x]);
}
set<int>st;
void dfs(int node)
{
  vis2[node]=1;st.insert(get(node));
  for(auto x:adj[node])
  {
    if(vis2[x])continue;
    dfs(x);
  }
}
int bruteForce(int l,int r)
{
  vector<int>clr;
  for(int i=l;i<=r;i++)
  {
    int u=ed[i].first,v=ed[i].second;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if(!vis[u])vis[u]=1,clr.push_back(u);
    if(!vis[v])vis[v]=1,clr.push_back(v);
  }
  int ret=0;
  for(auto x:clr)
  {
    if(vis2[x])continue;
    st.clear();dfs(x);
    ret+=st.size()-1;
  }
  for(auto x:clr)adj[x].clear(),vis[x]=0,vis2[x]=0;
  return ret;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,m,q;cin>>n>>m>>q;sq=sqrt(m)+2;
    ed.resize(m);
    for(int i=0;i<m;i++)
      cin>>ed[i].first>>ed[i].second;
    vector<vector<int> >qq(q);
    for(int i=0;i<q;i++)qq[i].resize(3);
    for(int i=0;i<q;i++)
    {
      cin>>qq[i][0]>>qq[i][1];qq[i][0]--,qq[i][1]--;
      qq[i][2]=i;
    }
    sort(qq.begin(),qq.end());
    int pt=0;
    for(int bl=0;bl<sq;bl++)
    {
      int l=bl*sq,r=(bl+1)*sq-1;
      for(int i=0;i<n;i++)par[i]=i;
      com=n;
      while(pt<q&&qq[pt][1]<=r)
        ans[qq[pt][2]]=com-bruteForce(qq[pt][0],qq[pt][1]),pt++;
      for(int i=r+1;i<n;i++)
      {
        int r1=get(ed[i].first),r2=get(ed[i].second);
        if(r1==r2)continue;com--;
        par[r1]=r2;
        if(pt<q&&qq[pt][0]<=r&&qq[pt][1]==i)
        {
          //cout<<"got it"<<endl;
          ans[qq[pt][2]]=com-bruteForce(qq[pt][0],r),pt++;
        }
      }
    }
    for(int i=0;i<q;i++)
      cout<<ans[i]<<"\n";
  }
  return 0;
}