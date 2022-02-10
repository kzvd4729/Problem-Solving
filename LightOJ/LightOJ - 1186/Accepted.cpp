/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 14:18:32                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 8                                          memory_used (MB): 2.9                             
*  problem: https://vjudge.net/problem/LightOJ-1186
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
const int N=1e5;
int a[N+2],b[N+2];
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];

    int xx=0;
    for(int i=1;i<=n;i++)xx^=(b[i]-a[i]-1);

    //for(int i=1;i<=n;i++)cout<<b[i]-a[i]-1;cout<<endl;

    if(xx==0)cout<<"Case "<<++tc<<": black wins\n";
    else cout<<"Case "<<++tc<<": white wins\n";
  }
  return 0;
}