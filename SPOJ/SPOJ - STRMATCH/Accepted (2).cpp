/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-06-01 19:58:55                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 1870                                       memory_used (MB): 16.4                            
*  problem: https://vjudge.net/problem/SPOJ-STRMATCH
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
//#define endl "\n"
using namespace std;
const int N=3e3;
int t,tc,last,n,sz,q,occur[N+N+2];
vector<int>length[N+2];
struct automata
{
  int len,link;
  map<char,int>next;
}st[N+N+2];
string s;
void insrt(char c)
{
  int now=++sz;
  st[now].len=st[last].len+1;
  occur[now]=1;

  int p,q;
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
      int cl=++sz;
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
void find_occur()
{
  for(int i=1;i<=sz;i++)
    length[st[i].len].push_back(i);
  for(int i=n;i>0;i--)
    for(int j=0,zz=length[i].size();j<zz;j++)
    {
      int x=length[i][j];
      occur[st[x].link]+=occur[x];
    }
  occur[0]=0;
}
int match(string s)
{
  int now=0;
  for(int i=0,zz=s.size();i<zz;i++)
  {
    if(!st[now].next[s[i]])return 0;
    now=st[now].next[s[i]];
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>n>>q;
  cin>>s;
  st[0].link=-1;
  for(int i=0;i<n;i++)
    insrt(s[i]);
  find_occur();
  while(q--)
  {
    cin>>s;
    cout<<occur[match(s)]<<endl;
  }
  return 0;
}