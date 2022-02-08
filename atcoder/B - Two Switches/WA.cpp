/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-12 18:48:23                      
*  solution_verdict: WA                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc070/tasks/abc070_b
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,ans;
int main()
{
    cin>>a>>b>>c>>d;
    if(c>b)
    {
        cout<<0<<endl;
        return 0;
    }
    cout<<min(b-c,d-c)<<endl;
    return 0;
}