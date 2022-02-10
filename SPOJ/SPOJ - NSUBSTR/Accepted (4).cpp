/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-08-07 01:48:54                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 170                                        memory_used (MB): 90.1                            
*  problem: https://vjudge.net/problem/SPOJ-NSUBSTR
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=250000;
int sz,last,occur[N+N+2];
int ans[N+2];
vector<int>v_len[N+2];
string s;
struct automata
{
  int len,link,next[27];
}st[N+N+2];
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
void whore(void)
{
  for(int i=1;i<=sz;i++)
    v_len[st[i].len].push_back(i);
  for(int i=s.size();i>=1;i--)
  {
    for(auto xx:v_len[i])
    {
      occur[st[xx].link]+=occur[xx];
      ans[i]=max(ans[i],occur[xx]);
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>s;
  st[0].link=-1;
  for(int i=0;s[i];i++)
    insrt(s[i]-'a');
  whore();
  for(int i=1;i<=s.size();i++)
    cout<<ans[i]<<"\n";

  return 0;
}