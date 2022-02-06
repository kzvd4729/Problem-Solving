/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/31/2017 21:26                        
*  solution_verdict: Wrong answer on hack 1                  language: GNU C++11                               
*  run_time: 15 ms                                           memory_used: 2000 KB                              
*  problem: https://codeforces.com/contest/761/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        if(a>100||a<0||b>100||b<0)cout<<"NO"<<endl;
        else if(abs(a-b)<=1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
     }
    return 0;
}