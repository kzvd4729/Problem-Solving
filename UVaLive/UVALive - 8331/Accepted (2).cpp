/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-21 22:55:40                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 182                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-8331
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e4;
int sz,last,n,q,ans;
string s;
struct automata
{
  int len,link,next[3];
}st[N+N+2];
void insrt(int c)
{
  int now=++sz;st[now].len=st[last].len+1;
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
      cl=++sz;st[cl].len=st[p].len+1;
      st[cl].link=st[q].link;
      memcpy(st[cl].next,st[q].next,sizeof(st[cl].next));
      for( ;p!=-1&&st[p].next[c]==q;p=st[p].link)
        st[p].next[c]=cl;
      st[now].link=st[q].link=cl;
    }
  }
  last=now;
}
void dfs(int lt,int rt,int now,int cnt)
{
  if(cnt>=ans||lt>rt)return ;
  if(s[lt-1]=='0')
  {
    if(st[now].next[0])
      dfs(lt+1,rt,st[now].next[0],cnt);
    else
      ans=min(ans,cnt);
    if(st[now].next[1])
      dfs(lt+1,rt,st[now].next[1],cnt+1);
    else
      ans=min(ans,cnt+1);
  }
  else
  {
    if(st[now].next[1])
      dfs(lt+1,rt,st[now].next[1],cnt);
    else
      ans=min(ans,cnt);
    if(st[now].next[0])
      dfs(lt+1,rt,st[now].next[0],cnt+1);
    else
      ans=min(ans,cnt+1);
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  while(cin>>n>>q)
  {
    if(n==0&&q==0)break;
    for(int i=0;i<=n+n;i++)
    {
      st[i].len=0;st[i].link=0;
      st[i].next[0]=0;st[i].next[1]=0;
      st[i].next[2]=0;
    }
    sz=0,last=0;st[0].link=-1;
    cin>>s;for(auto x:s)insrt(x-'0');
    while(q--)
    {
      int lt,rt;cin>>lt>>rt;ans=1e9;
      dfs(lt,rt,0,0);
      if(ans>N)cout<<"Impossible"<<endl;
      else cout<<ans<<endl;
    }
  }
  return 0;
}