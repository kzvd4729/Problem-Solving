/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/10/2017 19:31                        
*  solution_verdict: Wrong answer on test 4                  language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 100 KB                               
*  problem: https://codeforces.com/contest/140/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
#define pi acos(-1)
using namespace std;
double R,r,angle,n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>R>>r;
    angle=asin(r/(R-r));
    ///cout<<angle<<endl;
    if(angle*n>pi)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}