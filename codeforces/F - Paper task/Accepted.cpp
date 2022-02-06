/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/12/2018 16:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 2308 ms                                         memory_used: 50500 KB                             
*  problem: https://codeforces.com/contest/653/problem/F
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=5e5;
int n,neg[N+2],sz,last,seg[5*N+2],balance[N+2];
vector<int>vv[N+N+2];
struct automata
{
  int len,link,next[3];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz,p,q,cl;
  st[now].len=st[last].len+1;
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
      st[cl].len=st[p].len+1;st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[q].next));
       for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
void upd(int node,int lo,int hi,int id,int vl)
{
  if(lo==hi)
  {
    seg[node]=vl;return ;
  }
  int md=(lo+hi)/2;
  if(id<=md)upd(node*2,lo,md,id,vl);
  else upd(node*2+1,md+1,hi,id,vl);
  seg[node]=min(seg[node*2],seg[node*2+1]);
}
int qry(int node,int lo,int hi,int lt,int rt)
{
  if(lo>rt||hi<lt)return 1e9;
  if(lo>=lt&&hi<=rt)return seg[node];
  int md=(lo+hi)/2;
  return min(qry(node*2,lo,md,lt,rt),qry(node*2+1,md+1,hi,lt,rt));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>n>>s;int bl=0;
  for(int i=1;i<=n;i++)
  {
    if(s[i-1]=='(')bl++;else bl--;
    upd(1,1,n,i,bl);balance[i]=bl;
    vv[bl+N].push_back(i);
  }
  for(int i=0;i<=N+N;i++)sort(vv[i].begin(),vv[i].end());
  st[0].link=-1;long ans=0;
  for(int i=n;i>=1;i--)
  {
    insrt(s[i-1]-'(');
    int lcp=st[st[last].link].len;
    bl=balance[i-1];
     int lo=i,hi=n,md;
    while(hi-lo>2)
    {
      md=(lo+hi)/2;
      int qr=qry(1,1,n,i,md);
      if(qr<bl)hi=md;else lo=md;
    }
    for(md=lo;md<=hi;md++)
      if(qry(1,1,n,i,md)<bl)break;
    lo=i+lcp;hi=md-1;
    if(lo>hi)continue;
    ans+=(upper_bound(vv[bl+N].begin(),vv[bl+N].end(),hi)-lower_bound(vv[bl+N].begin(),vv[bl+N].end(),lo))*1LL;
  }
  cout<<ans<<endl;
  return 0;
}