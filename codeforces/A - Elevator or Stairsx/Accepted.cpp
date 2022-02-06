/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/18/2018 22:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1054/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);
   int x,y,z,t1,t2,t3;cin>>x>>y>>z>>t1>>t2>>t3;
   int str=abs(x-y)*t1;
  int lft=3*t3+abs(x-y)*t2+abs(x-z)*t2;
   if(str>=lft)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
   return 0;
}