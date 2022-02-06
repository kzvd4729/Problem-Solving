/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/13/2019 21:08                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/1100/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int t,tc;
double n,R,r;
const double pi=acos(-1.0);
int main()
{
    cin>>n>>R;
    double ang=pi/n;
    r=(R*sin(ang))/(1-sin(ang));
    cout<<setprecision(12)<<fixed<<r<<endl;
    return 0;
}