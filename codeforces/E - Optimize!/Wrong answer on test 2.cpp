/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/02/2020 16:57                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 8600 KB                              
*  problem: https://codeforces.com/contest/338/problem/E
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
const int N=2e5;
int tr;
struct treap
{
  int lt,rt,dt,pri,sz;
  int vl,lz,mn;
}bst[N+2];
void tooLazy(int nd)
{
  if(nd==0)return ;
  int x=bst[nd].lz,l=bst[nd].lt,r=bst[nd].rt;
   bst[nd].vl+=x;bst[nd].mn+=x;
  if(l)bst[l].lz+=x;if(r)bst[r].lz+=x;
   bst[nd].lz=0;
}
void cal(int nd)
{
  tooLazy(nd);
  int l=bst[nd].lt,r=bst[nd].rt;
  bst[nd].sz=bst[l].sz+bst[r].sz+1;
  bst[nd].mn=min({bst[nd].vl,bst[l].mn,bst[r].mn});
}
pair<int,int>splitbyValue(int nd,int vl)
{
  tooLazy(nd);tooLazy(bst[nd].lt);tooLazy(bst[nd].rt);
  if(!nd)return {0,0};pair<int,int>p;
  if(bst[nd].dt<=vl)
  {
    p=splitbyValue(bst[nd].rt,vl);
    bst[nd].rt=p.first;cal(nd);
    return {nd,p.second};
  }
  else
  {
    p=splitbyValue(bst[nd].lt,vl);
    bst[nd].lt=p.second;cal(nd);
    return {p.first,nd};
  }
}
int join(int lt,int rt)
{
  tooLazy(lt);tooLazy(bst[lt].lt);tooLazy(bst[lt].rt);
  tooLazy(rt);tooLazy(bst[rt].lt);tooLazy(bst[rt].rt);
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
int a[N+2],b[N+2],mx[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n,len,h;cin>>n>>len>>h;
  for(int i=1;i<=len;i++)cin>>b[i];
  for(int i=1;i<=n;i++)cin>>a[i];
   sort(b+1,b+len+1,greater<int>());
  int root=0;bst[0].mn=N;
   for(int i=1;i<=n;i++)
  {
    int lo=1,hi=len+1,md;
    while(lo<hi)
    {
      md=(lo+hi)/2;
      if(a[i]+b[md]<h)hi=md;else lo=md+1;
    }
    mx[i]=lo-1;
    //cout<<mx[i]<<" ";
  }
  //cout<<endl;
  int ans=0;
  for(int i=1;i<=n;i++)
  {
    pair<int,int>p=splitbyValue(root,a[i]-1);
    bst[p.second].lz--;tooLazy(p.second);
     int dt=mx[i]-1-bst[p.first].sz;
    bst[++tr]={0,0,a[i],rand(),1,dt,0,dt};
    root=join(join(p.first,tr),p.second);
     if(i>len)
    {
      int dl=a[i-len];
      p=splitbyValue(root,dl-1);
      //cout<<bst[p.first].sz<<" "<<bst[p.second].sz<<endl;
      pair<int,int>p2=splitbyValue(p.second,1);
       bst[p2.second].lz++;tooLazy(p2.second);
      //cout<<bst[root].sz<<" ";
      root=join(p.first,p2.second);
      //cout<<bst[root].sz<<endl;
    }
    if(i>=len&&bst[root].mn>=0)ans++;
  }
  cout<<ans<<endl;
  return 0;
}