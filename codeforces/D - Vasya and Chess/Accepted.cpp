/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/11/2018 14:12                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/493/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
int n;
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
   cin>>n;
  if(n%2==0)
    cout<<"white"<<endl<<1<<" "<<2<<endl;
  else cout<<"black"<<endl;
   return 0;
}