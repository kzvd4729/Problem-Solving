/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/02/2021 15:40                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 421 ms                                          memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/1548/problem/D1
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
const int N=1e6,inf=1e9,mod=1e9+7;
  int x[N+2],y[N+2],cnt[10+2][10+2];
 void add(int a,int b,int c)
{
  cnt[a%4][b%4]+=c;
}
bool ck(int a,int b,int c,int d,int e,int f)
{
  int gc=0;
   if(((abs(a-c))%4!=0) || ((abs(b-d))%4!=0))gc+=2;
  if(((abs(c-e))%4!=0) || ((abs(d-f))%4!=0))gc+=2;
  if(((abs(e-a))%4!=0) || ((abs(f-b))%4!=0))gc+=2;
   //if(gc%4==0)cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
   return ((gc%4)==0);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int n;cin>>n;
   for(int i=1;i<=n;i++)
  {
    cin>>x[i]>>y[i];
     add(x[i],y[i],+1);
  }
   long ans=0;
  for(int i=1;i<=n;i++)
  {
    add(x[i],y[i],-1);
    for(int j=i+1;j<=n;j++)
    {
      add(x[j],y[j],-1);
       ans+=ck(x[i]%4,y[i]%4,x[j]%4,y[j]%4,0,0)*cnt[0][0];
      ans+=ck(x[i]%4,y[i]%4,x[j]%4,y[j]%4,0,2)*cnt[0][2];
      ans+=ck(x[i]%4,y[i]%4,x[j]%4,y[j]%4,2,0)*cnt[2][0];
      ans+=ck(x[i]%4,y[i]%4,x[j]%4,y[j]%4,2,2)*cnt[2][2];
       add(x[j],y[j],+1);
     }
    add(x[i],y[i],+1);
  }
   cout<<ans/3<<endl;
    return 0;
}