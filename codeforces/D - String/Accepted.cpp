/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/25/2018 03:06                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 92 ms                                           memory_used: 40900 KB                             
*  problem: https://codeforces.com/contest/123/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=100000;
int sz,last,occur[N+N+2],occ[N+2];
long ans;
vector<int>v[N+2];
string s;
struct automata
{
  int len,link,next[26];
}st[N+N+N];
void insrt(int c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
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
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void occurences(void)
{
  for(int i=1;i<=sz;i++)
    v[st[i].len].push_back(i);
  for(int i=s.size();i>=1;i--)
    for(auto x:v[i])
      occur[st[x].link]+=occur[x];
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>s;
  st[0].link=-1;
  for(int i=0;s[i];i++)insrt(s[i]-'a');
   occurences();
   long pr=0;
  for(int i=1;i<=sz;i++)
    pr+=(((occur[i]*1LL*(occur[i]+1))/2)*(st[i].len-st[st[i].link].len));
  cout<<pr<<endl;
  return 0;
}