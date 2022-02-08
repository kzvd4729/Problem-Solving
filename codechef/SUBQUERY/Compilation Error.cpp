/****************************************************************************************
*  @author: kzvd4729                                         created: 21-10-2018 18:33:44                      
*  solution_verdict: Compilation Error                       language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 0M                                   
*  problem: https://www.codechef.com/problems/SUBQUERY
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int sz,last,occur[N+N+2];
vector<int>v_len[N+N+2];
map<int,int>mp[N+2];
void upd(int id,int idx,int vl)
{
  for( ;idx<=N;idx+=idx&-idx)
    mp[id][idx]+=vl;
}
int qry(int id,int idx)
{
  int ret=0;
  for( ;idx>0;idx-=idx&-idx)
    ret+=mp[id][idx];
  return ret;
}
struct automata
{
  int len,link,clone;
  int next[26];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;occur[now]=1;
  st[now].len=st[last].len+1;
  int p,q,cl;
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
      st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      st[cl].clone=1;
      memcpy(st[cl].next,st[q].next,sizeof(st[q].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void count_occurences(int len)
{
  for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
  for(int i=len;i>=1;i--)
  {
    for(auto x:v_len[i])
    {
      occur[st[x].link]+=occur[x];
    }
  }
  for(int i=1;i<=sz;i++)
    upd(occur[i],st[st[i].link].len+1,1);upd(occur[i],st[i].len+1,-1);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  string s;cin>>s;st[0].link=-1;
  for(auto x:s)insrt(x-'a');
  int len=s.size();count_occurences(len);
  int q;cin>>q;
  while(q--)
  {
    int l,p;cin>>l>>p;
    cout<<qry(p,l)<<"\n";
  }
  return 0;
}