/****************************************************************************************
*  @author: kzvd4729                                         created: 01-11-2018 14:43:50                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.04 sec                                        memory_used: 38.2M                                
*  problem: https://www.codechef.com/problems/MOU1H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e5;
const int mod=1e9+9;
int sz,last;
struct automata
{
  int len,link;
  map<int,int>next;
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
      st[cl].next=st[q].next;
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[q].link=st[now].link=cl;
    }
  }
  last=now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=0;i<=n+n;i++)
    {
      st[i].len=0;st[i].link=0;
      st[i].next.clear();
    }
    st[0].link=-1;sz=0,last=0;
    int rc=-1,ans=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;
      if(rc==-1)
      {
        rc=x;continue;
      }
      insrt(x-rc);
      ans+=i-1-st[st[last].link].len;
      ans%=mod;
      rc=x;
    }
    cout<<ans<<endl;
  }
  return 0;
}