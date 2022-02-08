/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-01-22 13:11:34                      
*  solution_verdict: AC                                      language: C++14 (GCC 5.4.1)                       
*  run_time: 1 ms                                            memory_used: 256 KB                               
*  problem: https://atcoder.jp/contests/abc086/tasks/abc086_b
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string a,b,c;
long num;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>a>>b;
    c=a+b;
    for(auto x:c)
    {
        num=num*10+x-'0';
    }
    long x=sqrt(num);
    if(x*x==num)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}