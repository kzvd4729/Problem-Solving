/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-12 18:41:25                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc070/tasks/abc070_a
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    cin>>s;
    if(s[0]==s[2])cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
     return 0;
}