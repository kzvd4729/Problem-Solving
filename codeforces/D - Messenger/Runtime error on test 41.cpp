/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/29/2018 18:02                        
*  solution_verdict: Runtime error on test 41                language: GNU C++17                               
*  run_time: 265 ms                                          memory_used: 53100 KB                             
*  problem: https://codeforces.com/contest/631/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const long N=2e5+1;
const long b=31;
long n,m,l,sz,last,vis[N];
char ch;
vector<long>tre[N],pos;
vector<pair<long,char> >in,pt;
struct automata
{
  long link,len,id;
  map<long,long>next;
}st[N+N];
void insrt(long c,long idx)
{
  long now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
   long p,q,cl;
  for(p=last;p!=-1&&!st[p].next[c];p=st[p].link)
    st[p].next[c]=now;
  if(p==-1)
    st[now].link=0;
  else
  {
    q=st[p].next[c];
    if(st[p].len+1==st[q].len)
      st[now].link=q;
    else
    {
      cl=++sz;
      st[cl].id=st[q].id;
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].next=st[q].next;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void suffix_tree(void)
{
  for(long i=1;i<=sz;i++)
    tre[st[i].link].push_back(i);
}
void case1(void)
{
  long ans=0;
  pair<long,char>p=pt[0];
  for(auto x:in)
  {
    if(x.second==p.second)
    {
      long tmp=max(0LL,x.first-p.first+1);
      ans=ans+tmp*1LL;
    }
  }
  cout<<ans<<endl;
}
void case2(void)
{
  long ans=0;
  pair<long,char>p1=pt[0];
  pair<long,char>p2=pt[1];
  for(long i=0;i<in.size()-1;i++)
  {
    if(in[i].second==p1.second&&in[i+1].second==p2.second)
        if(in[i].first>=p1.first&&in[i+1].first>=p2.first)
            ans++;
  }
  cout<<ans<<endl;
}
void dfs(long now)
{
  long tmp=st[now].id;
  if(vis[tmp]==0)pos.push_back(st[now].id);
  vis[tmp]=1;
  for(auto x:tre[now])
    dfs(x);
}
void case3(void)
{
  long now=0LL;
  for(long i=1;i<pt.size()-1;i++)
  {
    long x=pt[i].first*b+(pt[i].second)*1LL;
    if(st[now].next[x]==0)
    {
      cout<<0<<endl;
      return ;
    }
    now=st[now].next[x];
  }
  dfs(now);
  long nn=pt.size()-1,ans=0;
  for(auto x:pos)
  {
    if(pt.back().second==in[x].second&&in[x].first>=pt.back().first)
      if(pt[0].second==in[x-nn].second&&in[x-nn].first>=pt[0].first)
        ans++;
  }
  cout<<ans<<endl;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n>>m;
  st[0].link=-1;
  for(long i=1;i<=n;i++)
  {
    cin>>l;
    cin.ignore();
    cin>>ch;
     if(in.size()==0)
      in.push_back({l,ch});
    else
    {
      pair<long,char>p=in.back();
      if(p.second==ch)
      {
        in.pop_back();
        in.push_back({p.first+l,p.second});
      }
      else in.push_back({l,ch});
    }
  }
  //for(auto x:in)cout<<x.first<<" "<<x.second<<endl;
  for(long i=0;i<in.size();i++)
  {
    long x=in[i].first*b+(in[i].second)*1LL;
    //cout<<x<<endl;
    insrt(x,i+1);
  }
  for(long i=1;i<=m;i++)
  {
    cin>>l;
    cin.ignore();
    cin>>ch;
     if(pt.size()==0)
      pt.push_back({l,ch});
    else
    {
      pair<long,char>p=pt.back();
      if(p.second==ch)
      {
        pt.pop_back();
        pt.push_back({p.first+l,p.second});
        //pt[long(pt.size())-1]=p;
      }
      else pt.push_back({l,ch});
    }
  }
  suffix_tree();
  if(pt.size()==1)case1();
  else if(pt.size()==2)case2();
  else case3();
  return 0;
}