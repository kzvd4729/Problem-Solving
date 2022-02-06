/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/12/2020 20:56                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 15400 KB                             
*  problem: https://codeforces.com/contest/1380/problem/A
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
#include<unordered_map>
#include<random>
#include<chrono>
#include<stack>
#include<deque>
#define long long long  
using namespace std;
const int N=1e6;
int id[N+2],a[N+2],mn[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;mn[0]=1e9;
    for(int i=1;i<=n;i++)
    {
      cin>>a[i];
      if(a[i]<mn[i-1])mn[i]=a[i],id[i]=i;
      else mn[i]=mn[i-1],id[i]=id[i-1];
    }
    int rt=a[n],rd=n;
    int b=-1,c,d;
    for(int i=n-1;i>=2;i--)
    {
      if(rt<a[i]&&mn[i-1]<a[i])b=id[i-1],c=i,d=rd;
       if(a[i]<rt)rt=a[i],rd=i;
    }
    if(b==-1)cout<<"NO\n";
    else cout<<"YES\n"<<b<<" "<<c<<" "<<d<<"\n";
  }
  return 0;
}