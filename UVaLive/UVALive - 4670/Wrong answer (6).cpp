/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-10-18 21:05:55                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-4670
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e6;
int sz,last,occur[N+N+2];
vector<int>vLen[N+N+2];
struct node
{
  int len,link,next[26];
}aut[N+N+2];
void clean(int n)
{
  for(int i=0;i<=n+n;i++)
  {
    memset(aut[i].next,0,sizeof(aut[i].next));
    occur[i]=0;vLen[i].clear();
  }
  sz=0,last=0,aut[0].link=-1;
}
void insrt(int c)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  occur[now]=1;int p,q,cl;
  for(p=last;p!=-1&&!aut[p].next[c];p=aut[p].link)
    aut[p].next[c]=now;
  if(p==-1)
    aut[now].link=0;
  else
  {
    q=aut[p].next[c];
    if(aut[p].len+1==aut[q].len)
      aut[now].link=q;
    else
    {
      cl=++sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));//for array
      //aut[cl].next=aut[q].next;//for map
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  last=now;
}
void occurences(int n)
{
  for(int i=1;i<=sz;i++)
    vLen[aut[i].len].push_back(i);
  for(int i=n;i>=1;i--)
    for(auto x:vLen[i])
      occur[aut[x].link]+=occur[x];
}
int ret(string s)
{
  int now=0;
  for(auto x:s)
  {
    int c=x-'a';
    if(!aut[now].next[c])return -1;
    now=aut[now].next[c];
  }
  return now;
}
string s[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;while(cin>>n)
  {
    if(!n)break;
    for(int i=1;i<=n;i++)cin>>s[i];
    string tx;cin>>tx;clean((int)tx.size());
    for(auto x:tx)insrt(x-'a');
    occurences((int)tx.size());

    int mx=0;vector<int>ans;
    for(int i=1;i<=n;i++)
    {
      int stt=ret(s[i]);if(stt==-1)continue;
      if(occur[stt]>mx)
      {
        mx=occur[stt];ans.clear();
        ans.push_back(i);
      }
      else if(occur[stt]==mx)ans.push_back(i);
    }
    cout<<mx<<"\n";
    if(mx==0)
    {
      for(int i=1;i<=n;i++)
        cout<<s[i]<<"\n";
    }
    else for(auto x:ans)cout<<s[x]<<"\n";
  }
  return 0;
}