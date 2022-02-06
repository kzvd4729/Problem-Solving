/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/27/2018 14:16                        
*  solution_verdict: Wrong answer on test 23                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/702/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long d,k,a,b,t,cy,ty,rm,tm1,tm2,tm3;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>d>>k>>a>>b>>t;
     tm1=d*b;
    tm2=k*a+(d-k)*b;
    cy=d/k;
     tm3=cy*k*a+(cy-1)*t;
    rm=d-cy*k;
     tm3+=min(rm*b,t+rm*a);
     ///cout<<tm1<<" "<<tm2<<" "<<tm3<<endl;
    cout<<min(tm3,min(tm1,tm2))<<endl;
     return 0;
}