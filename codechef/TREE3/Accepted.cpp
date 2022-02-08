/****************************************************************************************
*  @author: kzvd4729                                         created: 28-04-2018 21:40:19                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 43.6M                                
*  problem: https://www.codechef.com/LTIME59A/problems/TREE3
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,t,u,v,mx,lvv[N+2];
set<int>adj[N+2];
vector<int>level[N+2],ans[N+2];
vector<int>tmp;
void find_lavel(int now,int par,int lv)
{
  level[lv].push_back(now);
  lvv[now]=lv;
  mx=max(mx,lv);
  set<int>::iterator it;
  for(it=adj[now].begin();it!=adj[now].end();it++)
  {
    int x=*it;
    if(x==par)continue;
    find_lavel(x,now,lv+1);
  }
}
bool cmp(int a,int b)
{
  return lvv[a]>lvv[b];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin>>t;
  while(t--)
  {
    cin>>n;
    mx=0;
    memset(lvv,0,sizeof(lvv));
    for(int i=0;i<=n;i++)
    {
      adj[i].clear();
      level[i].clear();
      ans[i].clear();
    }
    for(int i=1;i<n;i++)
    {
      cin>>u>>v;
      adj[u].insert(v);
      adj[v].insert(u);
    }
    find_lavel(1,-1,0);
    for(int i=mx;i>=0;i--)
    {
      for(auto x:level[i])
      {
        tmp.clear();
        set<int>::iterator it;
        for(it=adj[x].begin();it!=adj[x].end();it++)
          tmp.push_back(*it);
        sort(tmp.begin(),tmp.end(),cmp);
        int id=0;
        while(adj[x].size()>=3)
        {
          ans[x].push_back(tmp[id]);
          adj[x].erase(tmp[id]);
          adj[tmp[id]].erase(x);
          id++;
          ans[x].push_back(tmp[id]);
          adj[x].erase(tmp[id]);
          adj[tmp[id]].erase(x);
          id++;
          ans[x].push_back(tmp[id]);
          adj[x].erase(tmp[id]);
          adj[tmp[id]].erase(x);
          id++;
        }
      }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
      cnt+=adj[i].size();
    if(cnt)cout<<"NO"<<endl;
    else
    {
      cout<<"YES"<<endl;
      for(int i=1;i<=n;i++)
      {
        if(ans[i].size()==0)continue;
        int id=0;
        while(id<ans[i].size())
        {
          cout<<i<<" ";
          cout<<ans[i][id++]<<" ";
          cout<<ans[i][id++]<<" ";
          cout<<ans[i][id++]<<"\n";
        }
      }
    }
  }
  return 0;
}