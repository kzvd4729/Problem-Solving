/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-05-23 19:40:31                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11512
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e3;
int t,tc,sz,last;
struct automata
{
  int len,link,next[26];
}st[N+N+2];
string s,ans,tmp;
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
    if(st[q].len==st[p].len+1)
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin>>t;
  while(t--)
  {
    cin>>s;
    last=0,sz=0;
    memset(st,0,sizeof(st));
    st[0].link=-1;
    int mx=0,cnt=0;
    for(int i=s.size()-1;i>=0;i--)
    {
      insrt(s[i]-'A');
      int len=st[st[last].link].len;
      if(len<mx||len==0)continue;
      tmp=s.substr(i,len);
      if(len>mx)
      {
        mx=len;
        ans=tmp;
        cnt=2;
      }
      else
      {
        if(ans==tmp)cnt++;
        ans=min(ans,tmp);
      }
    }
    if(cnt==0)cout<<"No repetitions found!"<<endl;
    else cout<<ans<<" "<<cnt<<endl;
  }
  return 0;
}