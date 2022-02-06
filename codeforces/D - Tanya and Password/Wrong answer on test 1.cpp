/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/30/2019 18:54                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 43000 KB                             
*  problem: https://codeforces.com/contest/508/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int in[N+2],out[N+2];
map<string,int>mp;map<int,string>rv;
string ss[N+2];vector<int>adj[N+2],path;
bool eulerCircuit(int n,int start)
{
  for(int i=1;i<=n;i++)
    if(in[i]!=out[i])return false;
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
  /*for(auto x:path)
    cout<<x<<" ";
  cout<<endl;*/
  return true;
}
bool eulerPath(int n)
{
  int tin=-1,tot=-1,cnt=0;
  for(int i=1;i<=n;i++)
  {
    if(in[i]==out[i])continue;
    if(abs(in[i]-out[i])!=1)return 0;
    if(in[i]>out[i])tot=i;
    else tin=i;cnt++;
  }
  if(cnt!=2||tin==-1||tot==-1)return 0;
  adj[tot].push_back(tin);out[tot]++;in[tin]++;
  cout<<tot<<" -- "<<tin<<endl;
  eulerCircuit(n,tin);
  vector<int>tmp,res,lst;
  for(int i=1;i<path.size(); )
  {
    tmp.clear();tmp.push_back(tin);
    for(int j=i;j<path.size();j++)
    {
      if(path[j]==tin)break;
      tmp.push_back(path[j]);
    }
    if(tmp.size()==1)break;
    if(tmp.back()==tot)
      lst=tmp;
    else
    {
      for(auto x:tmp)
        res.push_back(x);
    }
    i+=tmp.size();
  }
  //lst.pop_back();
  for(auto x:lst)
    res.push_back(x);
  path=res;
  /*for(auto x:path)
    cout<<x<<" ";
  cout<<endl;*/
  return true;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<string>v;
  for(int i=1;i<=n;i++)
  {
    string s;cin>>s;ss[i]=s;
    v.push_back(s.substr(0,2));
    v.push_back(s.substr(1,2));
  }
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  for(int i=0;i<v.size();i++)
    mp[v[i]]=i+1,rv[i+1]=v[i];
  for(int i=1;i<=n;i++)
  {
    int u=mp[ss[i].substr(0,2)];
    int v=mp[ss[i].substr(1,2)];
    //cout<<u<<" *** "<<v<<endl;
    out[u]++,in[v]++;adj[u].push_back(v);
  }
  if(eulerCircuit(n,1));
  else if(eulerPath(n));
  else cout<<"NO"<<endl,exit(0);
  cout<<"YES"<<endl;
  string ans=rv[path[0]].substr(0,2);
  for(int i=1;i<path.size();i++)
    ans.push_back(rv[path[i]][1]);
  cout<<ans<<endl;
  return 0;
}