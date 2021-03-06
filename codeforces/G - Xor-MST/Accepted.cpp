/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/21/2019 15:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 811 ms                                          memory_used: 102600 KB                            
*  problem: https://codeforces.com/contest/888/problem/G
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int sz,par[N+2];
struct data
{
  int next[2],cnt,id;
}trie[4*N+2];
void add(int x,int id)
{
  int now=0;
  for(int i=29;i>=0;i--)
  {
    bool b=(x&(1<<i));
    if(!trie[now].next[b])trie[now].next[b]=++sz;
    now=trie[now].next[b];trie[now].cnt++;
  }
  if(id!=-1)trie[now].id=id;
}
void rem(int x)
{
  int now=0;
  for(int i=29;i>=0;i--)
  {
    bool b=(x&(1<<i));
    now=trie[now].next[b];trie[now].cnt--;
  }
}
pair<int,int>find(int x)
{
  int ret=0,now=0;
  for(int i=29;i>=0;i--)
  {
    bool b=(x&(1<<i));
    if(trie[trie[now].next[b]].cnt)
      now=trie[now].next[b];
    else
    {
      ret^=(1<<i);
      now=trie[now].next[!b];
    }
  }
  return {ret,trie[now].id};
}
vector<int>pp[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;cin>>n;vector<int>v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  sort(v.begin(),v.end());
   v.erase(unique(v.begin(),v.end()),v.end());
   n=v.size();
 //  for(int i=0;i<n;i++)cout<<v[i]<<" ";
//  cout<<endl;
    for(int i=0;i<n;i++)
    par[i]=i,add(v[i],i),pp[i].push_back(i);
 //  pair<int,int>b=find(6);
//  cout<<b.first<<" "<<b.second<<endl;
   set<pair<int,int> >st;
  for(int i=0;i<n;i++)st.insert({1,i});
  long mst=0;
  while(st.size()>1)
  {
    pair<int,int>p=*st.begin();st.erase(p);
    for(auto x:pp[p.second])
      rem(v[x]);
    int mn=2e9,id;
    for(auto x:pp[p.second])
    {
      pair<int,int>a=find(v[x]);
      if(a.first<mn)mn=a.first,id=a.second;
    }
    mst+=mn;st.erase({pp[par[id]].size(),par[id]});
    for(auto x:pp[p.second])
    {
      pp[par[id]].push_back(x);
      par[x]=par[id];add(v[x],-1);
    }
    st.insert({pp[par[id]].size(),par[id]});
  }
  cout<<mst<<endl;
  return 0;
}