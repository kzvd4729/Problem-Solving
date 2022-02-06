/****************************************************************************************
*  @author: kzvd4729#                                        created: Jun/10/2020 18:45                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 400 KB                               
*  problem: https://codeforces.com/contest/513/problem/B1
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
const int N=1e5;
int vs[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int n;long m;cin>>n>>m;long p=(1LL<<(n-1));
  for(int i=1;i<=n;i++)
  {
    p/=2;if(p==0)p=1;
    if(m<=p)cout<<i<<" ",vs[i]=1;
    else m-=p;
  }
  for(int i=n;i>=1;i--)if(vs[i]==0)cout<<i<<" ";
    cout<<endl;
  return 0;
}
/*
1 2 3 4 
1 2 4 3 
1 3 4 2 
1 4 3 2 
2 3 4 1 
2 4 3 1 
3 4 2 1 
4 3 2 1
*/