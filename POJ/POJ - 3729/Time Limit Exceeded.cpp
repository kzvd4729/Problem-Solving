/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-07-03 00:12:24                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/POJ-3729
****************************************************************************************/
#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<map>
#include<bitset>
#include<assert.h>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<set>
#include<queue>
//#include<unordered_map>
//#include<random>
//#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e5;
struct automata
{
  int len,link;
  map<int,int>next;
}aut[N+N+8];//2*insrt function call
int sz,last,occur[N+N+2];
void init(int n)
{
  for(int i=0;i<=n+n+2;i++)
  {
    aut[i].next.clear();occur[i]=0;
  }
  sz=0,last=0,aut[0].link=-1;
}
void insrt(int c)
{
  int now=++sz;aut[now].len=aut[last].len+1;
  int p,q,cl;occur[now]=1;
  for(p=last;p!=-1&&!aut[p].next.count(c);p=aut[p].link)aut[p].next[c]=now;
  if(p==-1)aut[now].link=0;
  else
  {
    q=aut[p].next[c];
    if(aut[p].len+1==aut[q].len)aut[now].link=q;
    else
    {
      cl=++sz;aut[cl].len=aut[p].len+1;
      aut[cl].link=aut[q].link;
      aut[cl].next=aut[q].next;
      //memcpy(aut[cl].next,aut[q].next,sizeof(aut[cl].next));
      for( ;p!=-1&&aut[p].next.count(c)==q;p=aut[p].link)aut[p].next[c]=cl;
      aut[now].link=aut[q].link=cl;
    }
  }
  last=now;
}
int a[N+2],n;
int calculate(int k)
{
  int now=0,ln=0,ret=0;
  for(int i=1;i<=n;i++)
  {
    if(aut[now].next.count(a[i]))ln++,now=aut[now].next[a[i]];
    else
    {
      int p;
      for(p=now;p!=-1&&!aut[p].next.count(a[i]);p=aut[p].link);
      if(p==-1)now=0,ln=0;
      else ln=aut[p].len+1,now=aut[p].next[a[i]];
    }
    if(ln==k)ret++;
  }
  return ret;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int m,k;
  while(~scanf("%d%d%d",&n,&m,&k))
  {
    //if(n==0)break;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);

    init(m);
    for(int i=1;i<=m;i++)
    {
      int x;scanf("%d",&x);insrt(x);
    }
    printf("%d\n",calculate(k));
    //cout<<calculate(k)<<endl;
    //cout<<calculate(k)-calculate(k+1)<<"\n";
    //cout<<endl;
  }
  
  return 0;
}