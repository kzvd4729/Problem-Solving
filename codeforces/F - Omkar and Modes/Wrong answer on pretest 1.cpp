/****************************************************************************************
*  @author: * kzvd4729                                       created: Jul/11/2020 22:59                        
*  solution_verdict: Wrong answer on pretest 1               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 7500 KB                              
*  problem: https://codeforces.com/contest/1372/problem/F
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
int n,ans[N+2];
int ask(int i)
{
  //if(ans[i])return ans[i];
  cout<<"? "<<i<<" "<<i<<endl;
  int x,f;cin>>x>>f;
  return x;
}
void solve(int lo,int hi,int l,int r)
{
  if(lo>hi)return;
  cout<<"? "<<lo<<" "<<hi<<endl;
  int x,f;cin>>x>>f;
   if(x==r)
  {
    for(int i=hi-f+1;i<=hi;i++)ans[i]=x;
    solve(lo,hi-f,l,-1);
  }
  else if(x==l)
  {
    for(int i=lo;i<=lo+f-1;i++)ans[i]=x;
    solve(lo+f,hi,-1,r);
  }
  else
  {
    for(int i=lo;i<=hi;i+=f)
    {
      int rt=ask(i);if(rt!=x)continue;
      solve(lo,i,l,x);solve(i,hi,x,r);
      break;
    }
  }
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;solve(1,n,-1,-1);
  cout<<"!";
  for(int i=1;i<=n;i++)cout<<" "<<ans[i];
  cout<<endl;
   return 0;
}