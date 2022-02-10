/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-29 10:51:22                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1778                                       memory_used (MB): 17.9                            
*  problem: https://vjudge.net/problem/HDU-4622
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e3;
int t,tc,sz,last,n;
int ans[N+2][N+2];
string s;
struct automata
{
  int len,link;
  int next[27];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;
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
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
int main()
{
  cin>>t;
  while(t--)
  {
    cin>>s;
    for(int i=s.size()-1;i>=0;i--)
    {
      memset(st,0,sizeof(st));
      st[0].link=-1;
      sz=0,last=0;
      int here=0;
      for(int j=i;j>=0;j--)
      {
        insrt(s[j]-'a');
        int lcp=st[st[last].link].len;
        here+=(i-j+1-lcp);
        ans[i+1][j+1]=here;
        ans[j+1][i+1]=here;
      }
    }
    int q,a,b;
    cin>>q;
    while(q--)
    {
      cin>>a>>b;
      cout<<ans[a][b]<<endl;
    }
  }
  return 0;
}