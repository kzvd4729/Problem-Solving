/****************************************************************************************
*  @author: * kzvd4729                                       created: May/07/2021 21:50                        
*  solution_verdict: Accepted                                language: GNU C++17 (64)                          
*  run_time: 265 ms                                          memory_used: 12000 KB                             
*  problem: https://codeforces.com/contest/1521/problem/C
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
 int ans[N+2];
 int p[N+2];
int type1(int x,int i,int j)
{
  //cout<<i<<" "<<j<<endl;
  cout<<"? "<<1<<" "<<i<<" "<<j<<" "<<x<<endl;
  int ret;cin>>ret;return ret;
   int pi,pj;cin>>pi>>pj;
  return max(min(x,pi),min(x+1,pj));
   return max(min(x,p[i]),min(x+1,p[j]));
}
 int type2(int x,int i,int j)
{
  //cout<<i<<" "<<j<<endl;
  cout<<"? "<<2<<" "<<i<<" "<<j<<" "<<x<<endl;
  int ret;cin>>ret;return ret;
   int pi,pj;cin>>pi>>pj;
  return min(max(x,pi),max(x+1,pj));
   return min(max(x,p[i]),max(x+1,p[j]));
}
 int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   // p[1]=2;
  // p[2]=5;
  // p[3]=3;
  // p[4]=4;
  // p[5]=1;
   int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
     int mid=-1;
    for(int i=1;i<=n;i+=2)
    {
      int r=type2(1,i,i+1);
       if(r==1)
      {
        mid=i;break;
      }
      else if(r==2)
      {
        int rr=type2(1,i+1,i);
        if(rr==1){mid=i+1;break;}
      }
      if(i+2==n)i--;
    }
    if(mid==-1)assert(0);
     ans[mid]=1;
    for(int i=1;i<=n;i++)
    {
      if(i==mid)continue;
      ans[i]=type1(n-1,mid,i);
    }
     cout<<"!";
    for(int i=1;i<=n;i++)cout<<" "<<ans[i];
      cout<<endl;
  }
      return 0;
}