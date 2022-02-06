/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/30/2020 21:04                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 61 ms                                           memory_used: 3900 KB                              
*  problem: https://codeforces.com/contest/1408/problem/C
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
const int N=1e6;
int a[N+2];
int main()  
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n,l;cin>>n>>l;
    for(int i=1;i<=n;i++)cin>>a[i];
     double st=0,ed=l,u=1,v=1;int p1=1,p2=n;
    double ans=0;
    while(p1<=p2)
    {
      double t1=((a[p1]-st)*1.0)/u;
       double t2=((ed-a[p2])*1.0)/v;
       if(t1<=t2)
      {
        ans+=t1;u++;st=a[p1];
        ed-=v*t1;p1++;
      }
      else
      {
        ans+=t2;v++;ed=a[p2];
        st+=u*t2;p2--;
      }
    }
    double lo=0,hi=1e9,md;
    for(int i=1;i<=100;i++)
    {
      md=(lo+hi)/2.0;
      double tst=st+u*md;
      double ted=ed-v*md;
      if(tst>ted)hi=md;else lo=md;
    }
    ans+=md;
    cout<<setprecision(10)<<fixed<<ans<<'\n';
  }
  return 0;
}