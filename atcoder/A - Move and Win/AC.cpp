/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-14 18:04:03                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/agc020/tasks/agc020_a
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a,b,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>a>>b;
    x=abs(a-b);
    if(x%2==0)cout<<"Alice"<<endl;
    else cout<<"Borys"<<endl;
     return 0;
}
 