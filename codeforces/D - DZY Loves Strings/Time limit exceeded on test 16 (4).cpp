/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/02/2019 01:42                        
*  solution_verdict: Time limit exceeded on test 16          language: GNU C++14                               
*  run_time: 3000 ms                                         memory_used: 79200 KB                             
*  problem: https://codeforces.com/contest/444/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
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
int sz,last,ind[N+N+2],ok[N+N+2];
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
vector<pair<int,int> >qr[N+2];
string aa[N+2],bb[N+2];int ans[N+2];
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
    mp[u[i]]=i;ok[i]=u[i].size();
    int p=get(u[i]);if(p)dfs(p,i);
    sort(oc[i].begin(),oc[i].end());
  }
  for(int i=1;i<=q;i++)
  {
    ans[i]=1e9;
    int a=mp[aa[i]],b=mp[bb[i]];
     if(oc[a].size()<=500&&oc[b].size()<=500)
    {
     if(oc[b].size()==0)continue;//P(oc[a]);P(oc[b]);
      int p=0;
      for(int j=0;j<oc[a].size();j++)
      {
        while(p+1<oc[b].size()&&oc[b][p+1]<oc[a][j])p++;
        //cout<<"*"<<p<<endl;
        int mn1=1e9,mn2=1e9;int q=p;
        if(oc[b][q]<oc[a][j])q++;
        if(q<oc[b].size())mn1=oc[b][q]-min(oc[a][j]-ok[a],oc[b][q]-ok[b]);
        if(oc[b][p]<=oc[a][j])mn2=oc[a][j]-min(oc[a][j]-ok[a],oc[b][p]-ok[b]);
        ans[i]=min(ans[i],min(mn1,mn2));
      }
      continue;
    }
    //qr[a].push_back(i);
    if(oc[a].size()<oc[b].size())
      qr[a].push_back({b,i});
    else qr[b].push_back({a,i});
  }
  for(int i=0;i<u.size();i++)
  {
    if(qr[i].size()==0)continue;
    for(auto x:oc[i])
    {
      for(auto z:qr[i])
      {
        int j=z.first;
         int id=lower_bound(oc[j].begin(),oc[j].end(),x)-oc[j].begin();
        if(id<oc[j].size())ans[z.second]=min(ans[z.second],oc[j][id]-min(x-ok[i],oc[j][id]-ok[j]));
        id--;
        if(id>=0)ans[z.second]=min(ans[z.second],x-min(x-ok[i],oc[j][id]-ok[j]));
      }
    }
  }
  for(int i=1;i<=q;i++)
  {
    if(ans[i]==1e9)ans[i]=-1;
    cout<<ans[i]<<" ";
  }
  cout<<endl;
   return 0;
}