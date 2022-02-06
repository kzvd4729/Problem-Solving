/****************************************************************************************
*  @author: kzvd4729#                                        created: May/30/2020 10:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 109 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/821/problem/B
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
#define long long long
using namespace std;
const int N=1e3;
int mt[N+2][N+2];
long sm(long x)
{
  return (x*(x+1))/2;
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int m,b;cin>>m>>b;long ans=0;
  for(int x=0;x<=10000000;x++)
  {
    int y=b-(x+m-1)/m;//cout<<x<<" "<<y<<endl;
    if(y<0)break;
    ans=max(ans,sm(x)*(y+1)+sm(y)*(x+1));
  }
  cout<<ans<<endl;
  return 0;
}