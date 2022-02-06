/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/09/2021 18:14                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 514 ms                                          memory_used: 18300 KB                             
*  problem: https://codeforces.com/contest/1553/problem/F
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
 const int N=6e5+10,inf=1e9;
 long bit[N+2];int cnt[N+2];
 void add(int x,long vl)
{
  for( ;x<=N;x+=x&-x)bit[x]+=vl,cnt[x]++;
}
pair<long,int>get(int x)
{
  long ret=0;int c=0;
  for( ;x>0;x-=x&-x)ret+=bit[x],c+=cnt[x];
   return {ret,c};
}
pair<long,int>getRange(int lo,int hi)
{
  pair<long,int>p1=get(hi);
  pair<long,int>p2=get(lo-1);
  return {p1.first-p2.first,p1.second-p2.second};
}
 void addRange(int lo,int hi,long vl)
{
  add(lo,vl);add(hi+1,-vl);
}
long getPoint(int x)
{
  return get(x).first;
}
 long sm[N+2];int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++)
  {
    for(int c=0; ;c++)
    {
      int x=c*a[i];if(x>300000)break;
       pair<long,int>p=getRange(x,x+a[i]-1);
       sm[i]+=p.first-1LL*p.second*x;
    }
    add(a[i],a[i]);
  }
   //for(int i=1;i<=n;i++)cout<<sm[i]<<" ";cout<<endl;
   memset(bit,0,sizeof bit);
   for(int i=1;i<=n;i++)addRange(a[i],a[i],1LL*a[i]*(i-1));
   //cout<<"HERE"<<endl;
   for(int i=1;i<=n;i++)
  {
    sm[i]+=getPoint(a[i]);
    //cout<<getPoint(a[i])<<" ";
    for(int c=1; ;c++)
    {
      int x=c*a[i];if(x>300000)break;
      addRange(x,x+a[i]-1,-x);
    }
  }
  //cout<<endl;
  for(int i=1;i<=n;i++)sm[i]+=sm[i-1];
  for(int i=1;i<=n;i++)cout<<sm[i]<<" ";cout<<endl;
   return 0;
}