/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 00:03                        
*  solution_verdict: Wrong answer on test 1                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 32100 KB                             
*  problem: https://codeforces.com/contest/444/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
template<typename T>//container
void P(T v)
{
  cerr<<"( ";
  for(auto x:v)cerr<<x<<" ";
  cerr<<")"<<endl;
}
struct automata
{
  int len,link,next[26];
}aut[N+N+2];
int sz,last,ind[N+N+2];
void init(void)
{
  aut[0].link=-1;
}
void insrt(int c,int id)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  int p,q,cl;ind[now]=id;
  for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
    aut[p].next[c]=now;
  if(p==-1)aut[now].link=0;
  else
  {
    q=aut[p].next[c];
    if(aut[p].len+1==aut[q].len)aut[now].link=q;
    else
    {
      cl=++sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;//ind[cl]=ind[q];
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  last=now;
}
vector<int>tree[N+N+2];
void makeTree()
{
  for(int i=1;i<=sz;i++)
    tree[aut[i].link].push_back(i);
}
vector<int>oc[N+N+2];
void dfs(int node,int id)
{
  if(ind[node])oc[id].push_back(ind[node]);
  for(auto x:tree[node])
    dfs(x,id);
}
int get(string &s)
{
  int now=0;
  for(auto x:s)
  {
    if(aut[now].next[x-'a'])now=aut[now].next[x-'a'];
    else return 0;
  }
  return now;
}
string aa[N+2],bb[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   string s;cin>>s;init();
  for(int i=0;i<s.size();i++)
    insrt(s[i]-'a',i+1);
   makeTree();
   int q;cin>>q;vector<string>u;
  for(int i=1;i<=q;i++)
  {
    cin>>aa[i]>>bb[i];
    u.push_back(aa[i]);u.push_back(bb[i]);
  }
  sort(u.begin(),u.end());
  u.erase(unique(u.begin(),u.end()),u.end());
   map<string,int>mp;
  for(int i=0;i<u.size();i++)
  {
    mp[u[i]]=i;
    int p=get(u[i]);if(p)dfs(p,i);
    sort(oc[i].begin(),oc[i].end());
     // cout<<u[i]<<"----: ";
    // for(auto x:oc[i])
    //  cout<<x<<" ";
    // cout<<endl;
  }
  vector<int>a,b;
  for(int i=1;i<=q;i++)
  {
    a=oc[mp[aa[i]]],b=oc[mp[bb[i]]];
    int n=aa[i].size(),m=bb[i].size();
    if(a.size()>b.size())swap(a,b),swap(m,n);
    // P(a);P(b);
    int mn=1e9;
     for(auto x:a)
    {
      int id=lower_bound(b.begin(),b.end(),x)-b.begin();
      if(id<b.size())mn=min(mn,b[id]-min(x-n,b[id]-m));
      id--;
      if(id>=0)mn=min(mn,x-min(x-n,b[id]-m));
    }
    if(mn==1e9)mn=-1;
    cout<<mn<<"\n";
  }
   return 0;
}