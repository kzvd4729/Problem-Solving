/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-10-20 19:45:17                      
*  solution_verdict: Runtime Error                           language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1255
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int length,n,sz,last,occur[N+N+2],q,f;
string s;
vector<int>v_len[N+N+2];
struct automata
{
  int len,link,id,clone,next[26];
}st[N+N+2];
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
      st[cl].clone=1;
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
  for(int i=1;i<=length;i++)
  {
    v_len[i].clear();
  }
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
int ans(string s)
{
  int now=0;
  for(int i=0;s[i];i++)
  {
    int c=s[i]-'a';
    if(st[now].next[c])
      now=st[now].next[c];
    else
    {
      return 0;
    }
  }
  return occur[now];
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    cin>>s;
    length=s.size();
    for(int i=0;i<=N+N;i++)
    {
      st[i].len=0;st[i].link=0;
      memset(st[i].next,0,sizeof(st[i].next));
    }
    memset(occur,0,sizeof(occur));
    st[0].link=-1,sz=0,last=0;
    for(int i=0;i<length;i++)insrt(s[i]-'a',i+1);
    count_occurrence();
    string pt;cin>>pt;
    cout<<"Case "<<++tc<<": "<<ans(pt)<<endl;
  }
  return 0;
}