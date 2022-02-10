/****************************************************************************************
*  @author: kzvd4729                                         created: 2020-09-08 18:13:07                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1296
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
int grundy(int x)
{
  for(int p=0; ;p++)
  {
    int bg=(1<<p)-1,gp=(1<<(p+1));
    if((x-bg)%gp==0)return (x-bg)/gp;
  }
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);

  int t,tc=0;cin>>t;
  while(t--)
  {
    int n;cin>>n;int xx=0;
    for(int i=1;i<=n;i++)
    {
      int x;cin>>x;xx^=grundy(x);
    }
    if(xx==0)cout<<"Case "<<++tc<<": Bob\n";
    else cout<<"Case "<<++tc<<": Alice\n";
  }
  return 0;
}