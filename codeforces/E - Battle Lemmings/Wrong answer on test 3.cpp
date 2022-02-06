/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/26/2021 19:59                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 7800 KB                              
*  problem: https://codeforces.com/contest/1420/problem/E
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N=1e6,inf=1e9,mod=998244353;
 int a[N+2],mx,n;
int cal()
{
  int cnt=0,ret=mx;
  for(int i=1;i<=n;i++)
  {
    if(a[i]==0)cnt++;
    else
    {
      ret-=(cnt*(cnt-1))/2;
      cnt=0;
    }
  }
  ret-=(cnt*(cnt-1))/2;
  return ret;
}
int pr[N+2],ans;
int tryE()
{
  int now=ans,id=-1,f,pad=-1;
  for(int i=1;i<=n;i++)
  {
    if(a[i]==0)continue;
     if(i>1 && a[i-1]==0 && pr[i]!=1)
    {
      swap(a[i],a[i-1]);
            int ad=0;
      for(int j=i;j<=n;j++)
      {
        if(a[j]==1)break;
        ad++;
      }
       int c=cal();
      if(c>now)now=c,id=i,f=-1,pad=-1;
      else if(now==c && ad>pad)pad=ad,id=i,f=-1;
       swap(a[i],a[i-1]);
    }
    if(i<n && a[i+1]==0 && pr[i]!=-1)
    {
      swap(a[i],a[i+1]);
       int ad=0;
      for(int j=i;j>=1;j--)
      {
        if(a[j]==1)break;
        ad++;
      }
       int c=cal();
      if(c>now)now=c,id=i,f=1,pad=-1;
      else if(now==c && ad>pad)pad=ad,id=i,f=1;
       swap(a[i],a[i+1]);
    }
  }
  //cout<<id<<endl;
  if(id!=-1)
  {
    swap(a[id],a[id+f]);
    pr[id+f]=f;pr[id]=0;
  }
  return now;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i],mx+=(!a[i]);
   mx=(mx*(mx-1))/2;
   ans=cal();cout<<ans<<" ";
  for(int k=1;k<=(n*(n-1))/2;k++)
  {
    ans=tryE();
    //for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<"  "<<ans<<endl;
    cout<<ans<<" ";
  }
  cout<<endl;
    return 0;
}