/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2020 17:49                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 62900 KB                             
*  problem: https://codeforces.com/gym/102465/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6,inf=1e9;
vector<pair<int,int> >adj[N+2];
int ds[4][N+2];
 int d[N+2],qd[N+2];
void spfa(int n,int sr)
{
  for(int i=1;i<=n;i++)d[i]=inf,qd[i]=0;
  queue<int>q;q.push(sr);qd[sr]=1,d[sr]=0;
  while(q.size())
  {
    int u=q.front();q.pop();qd[u]=0;
    for(auto x:adj[u])
    {
      if(d[u]+x.second<d[x.first])
      {
        d[x.first]=d[u]+x.second;
        if(!qd[x.first])q.push(x.first),qd[x.first]=1;
      }
    }
  }
}
vector<vector<int> >simplify(vector<vector<int> >v)
{
  vector<vector<int> >u;v.push_back({-1,-1,-1});
  vector<pair<int,int> >tmp;tmp.push_back({v[0][1],v[0][2]});
  for(int i=1;i<v.size();i++)
  {
    if(v[i][0]==v[i-1][0])tmp.push_back({v[i][1],v[i][2]});
    else
    {
      sort(tmp.begin(),tmp.end());
      u.push_back({v[i-1][0],tmp[0].first,tmp[0].second});
      pair<int,int>l=tmp[0];
      for(int j=1;j<tmp.size();j++)
      {
        if(tmp[j].second>l.second||(tmp[j].second==l.second&&tmp[j].first>l.first))
          continue;
        l=tmp[j];u.push_back({v[i-1][0],l.first,l.second});
      }
      tmp.clear();tmp.push_back({v[i][1],v[i][2]});
    }
  }
  sort(u.begin(),u.end());
  return u;
}
 //..............................................................
int tr;
struct treap
{
  int lt,rt,dt,sc,pri,sz,mn;
}bst[N+2];
void cal(int node)
{
  int l=bst[node].lt,r=bst[node].rt;
  bst[node].sz=bst[l].sz+bst[r].sz+1;
  bst[node].mn=min({bst[node].sc,bst[l].mn,bst[r].mn});
}
//left tree will contain value <= vl.
pair<int,int>splitbyValue(int node,int vl)
{
  if(!node)return {0,0};pair<int,int>p;
  if(bst[node].dt<=vl)
  {
    p=splitbyValue(bst[node].rt,vl);
    bst[node].rt=p.first;cal(node);
    return {node,p.second};
  }
  else
  {
    p=splitbyValue(bst[node].lt,vl);
    bst[node].lt=p.second;cal(node);
    return {p.first,node};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,m;cin>>n>>m;
  while(m--)
  {
    int u,v,w;cin>>u>>v>>w;u++,v++;
    adj[u].push_back({v,w});adj[v].push_back({u,w});
  }
  spfa(n,1);for(int i=1;i<=n;i++)ds[1][i]=d[i];
  spfa(n,2);for(int i=1;i<=n;i++)ds[2][i]=d[i];
  spfa(n,3);for(int i=1;i<=n;i++)ds[3][i]=d[i];
   vector<vector<int> >v;
  for(int i=1;i<=n;i++)
  {
    v.push_back({ds[1][i],ds[2][i],ds[3][i]});
    //cout<<ds[1][i]<<" "<<ds[2][i]<<" "<<ds[3][i]<<endl;
  }
  //cout<<endl<<endl;
   sort(v.begin(),v.end());
  // for(auto x:v)
  //   cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
  // cout<<endl<<endl;
   v=simplify(v);
  // for(auto x:v)
  //   cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
   int ans=v.size(),root=0;
  v.push_back({-1,-1,-1});
//int lt,rt,dt,sc,pri,sz,mn;
  int pt=0;bst[0]={0,0,-inf,inf,rand(),0,inf};
  for(int i=1;i<v.size();i++)
  {
    if(v[i][0]==v[i-1][0])continue;
    for(int j=pt;j<i;j++)
    {
      pair<int,int>p=splitbyValue(root,v[j][1]);
      if(bst[p.first].mn<=v[j][2])ans--;
      root=join(p.first,p.second);
    }
    for(int j=pt;j<i;j++)
    {
      bst[++tr]={0,0,v[j][1],v[j][2],rand(),1,inf};
       pair<int,int>p=splitbyValue(root,v[j][1]);
      root=join(join(p.first,tr),p.second);
    }
    pt=i;
  }
  cout<<ans<<endl;
  return 0;
}