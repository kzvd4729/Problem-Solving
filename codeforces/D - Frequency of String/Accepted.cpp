/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/19/2018 22:29                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 1465 ms                                         memory_used: 37600 KB                             
*  problem: https://codeforces.com/contest/963/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
int length,n,sz,last,occur[N+N+2],q,x;
string s;
vector<int>v_len[N+N+2],tre[N+N+2],pos;
struct automata
{
  int len,link,id,clone,next[26];
}st[N+N];
void insrt(int c,int idx)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  st[now].id=idx;
  occur[now]=1;
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
      st[cl].id=st[q].id;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
       for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
void count_occurrence(void)
{
  for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
   for(int i=length;i>=1;i--)
  {
    for(int j=0;j<v_len[i].size();j++)
    {
      int tmp=v_len[i][j];
      occur[st[tmp].link]+=occur[tmp];
    }
  }
}
void make_suffixtree(void)
{
  for(int i=1;i<=sz;i++)
    tre[st[i].link].push_back(i);
}
void find_path(int now,int ssz)
{
  pos.push_back(st[now].id-ssz+1);
  for(auto x:tre[now])
    find_path(x,ssz);
}
void position_of_occurrence(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!st[now].next[c])return ;
    now=st[now].next[c];
  }
  find_path(now,s.size());
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  length=s.size();
  st[0].link=-1;
  for(int i=0;i<length;i++)insrt(s[i]-'a',i+1);
   //count_occurrence();
  make_suffixtree();
   cin>>q;
  while(q--)
  {
    cin>>x>>s;
    pos.clear();
    position_of_occurrence(s);
    sort(pos.begin(),pos.end());
    pos.resize(distance(pos.begin(),unique(pos.begin(),pos.end())));
     int ans=1e8;
    for(int i=0;i<pos.size();i++)
    {
      if(i>=x-1)
        ans=min(ans,pos[i]-pos[i-x+1]+(int)s.size());
    }
    if(ans==1e8)ans=-1;
    cout<<ans<<" ";
  }
  return 0;
}