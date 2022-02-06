/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/15/2018 21:35                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 3300 KB                              
*  problem: https://codeforces.com/contest/867/problem/B
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
if(n==1)cout<<1<<" "<<1<<endl<<1<<endl;
else cout<<(n-1)*2<<" "<<2<<endl<<1<<" "<<2<<endl;
return 0;
}