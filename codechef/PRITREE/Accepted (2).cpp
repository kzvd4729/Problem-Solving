/****************************************************************************************
*  @author: kzvd4729                                         created: 03-11-2018 01:20:50                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.19 sec                                        memory_used: 34.1M                                
*  problem: https://www.codechef.com/NOV18A/problems/PRITREE
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
const int R=2e7;
int aa[N+2],sub[N+2],cnt,mx,sum;
bool vis[R+2];
vector<int>adj[N+2];
void seive(void)
{
  vis[0]=1;vis[1]=1;int lm=sqrt(R+1);
  for(int i=4;i<=R;i+=2)vis[i]=1;
  for(int i=3;i<=R;i+=2)
  {
    if(vis[i])continue;
    if(i>lm)continue;
    for(int j=i*i;j<=R;j+=2*i)
      vis[j]=1;
  }
}
int dfs(int node,int par)
{
  sub[node]=aa[node];
  for(auto x:adj[node])
  {
    if(x==par)continue;
    sub[node]+=dfs(x,node);
  }
  return sub[node];
}
void dds(int node,int par)
{
  if(par!=-1)
  {
    if(vis[sum-sub[node]]==0)cnt++;
    if(vis[sub[node]]==0)cnt++;
    //cout<<sub[node]<<"--"<<sum-sub[node]<<endl;
  }
  for(auto x:adj[node])
  {
    if(x==par)continue;
    dds(x,node);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  seive();
  int n;cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>aa[i];sum+=aa[i];
  }
  vector<pair<int,int> >ed,pr;
  int loop=1000;
  while(loop--)
  {
    for(int i=1;i<=n;i++)adj[i].clear();
    ed.clear();
    vector<int>dn,un;
    dn.push_back(1);
    for(int i=2;i<=n;i++)un.push_back(i);
    srand(loop);
    random_shuffle(un.begin(),un.end());
    while(un.size())
    {
      int id=rand()%((int)dn.size());
      ed.push_back({dn[id],un.back()});
      adj[dn[id]].push_back(un.back());
      adj[un.back()].push_back(dn[id]);
      dn.push_back(un.back());
      un.pop_back();
    }
//    for(auto x:ed)
//      cout<<x.first<<" "<<x.second<<endl;
//    cout<<endl;
    //cout<<endl;
    dfs(1,-1);cnt=0;dds(1,-1);
    if(cnt>mx)
    {
      mx=cnt;pr=ed;
    }
  }
  //cout<<mx<<endl;
  for(auto x:pr)
    cout<<x.first<<" "<<x.second<<"\n";
  return 0;
}