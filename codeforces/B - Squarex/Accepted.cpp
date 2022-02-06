/****************************************************************************************
*  @author: kzvd4729                                         created: May/07/2020 20:11                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3600 KB                              
*  problem: https://codeforces.com/contest/1351/problem/B
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
#define long long long
using namespace std;
const int N=1e6,mod=1e9+7;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  int t;cin>>t;
  while(t--)
  {
    int a,b,c,d;cin>>a>>b>>c>>d;
    if(a==c&&b+d==a){cout<<"Yes\n";continue;}
    if(a==d&&b+c==a){cout<<"Yes\n";continue;}
    if(b==c&&a+d==b){cout<<"Yes\n";continue;}
    if(b==d&&a+c==b){cout<<"Yes\n";continue;}
    cout<<"No\n";
  }
    return 0;
}