/****************************************************************************************
*  @author: kzvd4729                                         created: 09-03-2021 21:24:39                      
*  solution_verdict: Accepted                                language: C++17                                   
*  run_time: 0.05 sec                                        memory_used: 9.8M                                 
*  problem: https://www.codechef.com/MARCH21A/problems/SPACEARR
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
int a[N+2];
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    long sm=0;
    for(int i=1;i<=n;i++)
    {
      if(a[i]>i){sm=0;break;}
      sm+=(i-a[i]);
    }
    if(sm%2)cout<<"First"<<endl;
    else cout<<"Second"<<endl;
  }
    return 0;
}