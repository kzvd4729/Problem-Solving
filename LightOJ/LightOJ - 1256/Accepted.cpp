/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-07-03 19:43:11                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 25                                         memory_used (MB): 10                              
*  problem: https://vjudge.net/problem/LightOJ-1256
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int vis[26],cnt,in[N+2],out[N+2];
vector<int>adj[26],path;
map<pair<int,int>,vector<string> >mp;
void dfs(int node)
{
  if(vis[node])return ;
  vis[node]=1;cnt++;
  for(int i=0;i<adj[node].size();i++)
    dfs(adj[node][i]);
}
bool eulerCircuit(vector<int>vec,int start)
{
  for(int i=0;i<vec.size();i++)
    if(in[vec[i]]!=out[vec[i]])return false;
  for(int i=0;i<vec.size();i++)
  {
    memset(vis,0,sizeof(vis));
    cnt=0;dfs(vec[i]);if(cnt!=vec.size())return 0;
  }
  stack<int>st;st.push(start);
  while(!st.empty())
  {
    int u=st.top();
    if(adj[u].size()==0)
    {
      path.push_back(u);
      st.pop();
    }
    else
    {
      st.push(adj[u].back());
      adj[u].pop_back();
    }
  }
  reverse(path.begin(),path.end());
  return true;
}
bool eulerPath(vector<int>vec)
{
  int tin=-1,tot=-1,cot=0;
  for(int i=0;i<vec.size();i++)
  {
    if(in[vec[i]]==out[vec[i]])continue;
    if(abs(in[vec[i]]-out[vec[i]])!=1)return 0;
    if(in[vec[i]]>out[vec[i]])tot=vec[i];
    else tin=vec[i];cot++;
  }
  if(cot!=2||tin==-1||tot==-1)return 0;
  adj[tot].push_back(tin);out[tot]++;in[tin]++;
  if(!eulerCircuit(vec,tin))return false;
  vector<int>tmp,res,lst;
  for(int i=1;i<path.size(); )
  {
    tmp.clear();tmp.push_back(tin);
    for(int j=i;j<path.size();j++)
    {
      if(path[j]==tin)break;
      tmp.push_back(path[j]);
    }
    if(tmp.back()==tot&&lst.size()==0)
      lst=tmp;
    else
    {
      for(auto x:tmp)
        res.push_back(x);
    }
    i+=tmp.size();
  }
  for(auto x:lst)
    res.push_back(x);
  path=res;
  return true;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;vector<int>vec;
    mp.clear();int bad=0;path.clear();
    for(int i=0;i<26;i++)adj[i].clear();
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    for(int i=1;i<=n;i++)
    {
      string s;cin>>s;
      int u=s[0]-'a',v=s.back()-'a';
      vec.push_back(u);vec.push_back(v);
      adj[u].push_back(v);out[u]++;in[v]++;
      mp[{u,v}].push_back(s);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    if(!eulerCircuit(vec,vec[0]))
      if(!eulerPath(vec))
        bad=1;
    if(bad||path.size()!=n+1)cout<<"Case "<<++tc<<": No\n";
    else
    {
      cout<<"Case "<<++tc<<": Yes\n";
      int f=0;
      for(int i=0;i<path.size()-1;i++)
      {
        if(f)cout<<" ";f=1;
        cout<<mp[{path[i],path[i+1]}].back();
        mp[{path[i],path[i+1]}].pop_back();
      }
      cout<<"\n";
    }
  }
  return 0;
}