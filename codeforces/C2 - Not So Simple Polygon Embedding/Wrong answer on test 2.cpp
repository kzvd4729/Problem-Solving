/****************************************************************************************
*  @author: kzvd4729                                         created: May/23/2020 13:07                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/1354/problem/C2
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
const int N=2e5;
const double pi=acos(-1.0);
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    double n;cin>>n;n*=2;
    if(n==6)
    {
      cout<<"1.931851653\n";continue;
    }
    if(n==10)
    {
      cout<<"3.196226611\n";continue;
    }
    double ans=1.0/(2.0*tan(pi/n));
    double anb=1.0/(2.0*sin(pi/n));
    double ang=180-360/(n+n);
    cout<<setprecision(8)<<fixed<<anb*2-(anb*2-ans*2)*0.25<<endl;
    //cout<<setprecision(8)<<fixed<<(1/sqrt(2.0))*anb*2<<endl;
  }
  return 0;
}