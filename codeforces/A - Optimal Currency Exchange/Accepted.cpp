/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/04/2019 15:10                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1214/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
  long n,d,e;cin>>n>>d>>e;
  e*=5;
  long mn=1e9;
  for(long i=0; ;i++)
  {
    long ee=e*i;
    if(ee>n)break;
    long rm=n-ee;
     mn=min(mn,rm%d);
  }
  cout<<mn<<endl;
  return 0;
}