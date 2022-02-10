/****************************************************************************************
*  @author: kzvd4729                                         created: 2019-01-21 23:01:00                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 179                                        memory_used (MB):                                 
*  problem: https://vjudge.net/problem/UVALive-8331
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n,q,ans;
string s;
/***************** Automata **********************/
const int A=1e4;
int Sz,Last;
struct Automata
{
  int len,link,next[3];
}aut[A+A+2];
void insrt(int c)
{
  int now=++Sz;aut[now].len=aut[Last].len+1;
  int p,q,cl;
  for(p=Last;p!=-1&&!aut[p].next[c];p=aut[p].link)
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
      cl=++Sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;
      memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next[c]==q;p=aut[p].link)
        aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  Last=now;
}
///////////////////////////////////////////
void dfs(int lt,int rt,int now,int cnt)
{
  if(cnt>=ans||lt>rt)return ;
  if(s[lt-1]=='0')
  {
    if(aut[now].next[0])
      dfs(lt+1,rt,aut[now].next[0],cnt);
    else
      ans=min(ans,cnt);
    if(aut[now].next[1])
      dfs(lt+1,rt,aut[now].next[1],cnt+1);
    else
      ans=min(ans,cnt+1);
  }
  else
  {
    if(aut[now].next[1])
      dfs(lt+1,rt,aut[now].next[1],cnt);
    else
      ans=min(ans,cnt);
    if(aut[now].next[0])
      dfs(lt+1,rt,aut[now].next[0],cnt+1);
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
      aut[i].len=0;aut[i].link=0;
      aut[i].next[0]=0;aut[i].next[1]=0;
      aut[i].next[2]=0;
    }
    Sz=0,Last=0;aut[0].link=-1;
    cin>>s;for(auto x:s)insrt(x-'0');
    while(q--)
    {
      int lt,rt;cin>>lt>>rt;ans=1e9;
      dfs(lt,rt,0,0);
      if(ans>A)cout<<"Impossible"<<endl;
      else cout<<ans<<endl;
    }
  }
  return 0;
}