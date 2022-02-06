/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/26/2020 21:25                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 1214 ms                                         memory_used: 7100 KB                              
*  problem: https://codeforces.com/contest/213/problem/E
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
#include<sstream> 
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<stack>
#include<deque>
#include<random>
#define long long long
using namespace std;
const int N=2e5,b=1011001,mod=1e9+7;
int tr,pw[N+2];
struct treap
{
  int lt,rt,dt,pri,sz;
  int hs;
}bst[N+2];
void cal(int nd)
{
  assert(nd);
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
   bst[nd].hs=(1LL*bst[l].hs*b+bst[nd].dt)%mod;
  bst[nd].hs=(1LL*bst[nd].hs*pw[bst[r].sz]+bst[r].hs)%mod;
}
pair<int,int>splitbySize(int nd,int ss)
{
  if(!nd)return {0,0};pair<int,int>p;
  if(bst[bst[nd].lt].sz>=ss)
  {
    p=splitbySize(bst[nd].lt,ss);
    bst[nd].lt=p.second;cal(nd);
    return {p.first,nd};
  }
  else
  {
    p=splitbySize(bst[nd].rt,ss-bst[bst[nd].lt].sz-1);
    bst[nd].rt=p.first;cal(nd);
    return {nd,p.second};
  }
}
int join(int lt,int rt)
{
  if(!lt)return rt;if(!rt)return lt;
  if(bst[lt].pri>=bst[rt].pri)
  {
    bst[lt].rt=join(bst[lt].rt,rt);
    cal(lt);return lt;
  }
  else
  {
    bst[rt].lt=join(lt,bst[rt].lt);
    cal(rt);return rt;
  }
}
int bit[N+2];
void add(int x,int vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl;
}
int get(int x)
{
  int ret=0;
  for( ;x>0;x-=x&-x)ret+=bit[x];
  return ret;
}
int po[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  pw[0]=1;
  for(int i=1;i<=N;i++)pw[i]=(1LL*pw[i-1]*b)%mod;
   int n,m;cin>>n>>m;int hs=0;
  for(int i=1;i<=n;i++)
  {
    int x;cin>>x;
    hs=(1LL*hs*b+x)%mod;
  }
  int tt=0;
  for(int i=n-1;i>=0;i--)tt=(tt+pw[i])%mod;
   int root=0;
  for(int i=1;i<=m;i++)
  {
    int x;cin>>x;po[x]=i;
     if(x>n)continue;
    bst[++tr]={0,0,x,rand(),1,x};
    root=join(root,tr);add(i,1);
  }
  int ans=(bst[root].hs==hs);
  for(int i=n+1;i<=m;i++)
  {
    int dl=i-n;add(po[dl],-1);
    pair<int,int>p1=splitbySize(root,get(po[dl]));
    pair<int,int>p2=splitbySize(p1.second,1);
    root=join(p1.first,p2.second);
     bst[++tr]={0,0,i,rand(),1,i};
    p1=splitbySize(root,get(po[i]));
    root=join(p1.first,join(tr,p1.second));
    add(po[i],1);
     hs=(hs+tt)%mod;
    ans+=(hs==bst[root].hs);
  }
  cout<<ans<<endl;
  return 0;
}