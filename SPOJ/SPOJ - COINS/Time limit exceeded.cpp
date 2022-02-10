/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-08 18:50:53                      
*  solution_verdict: Time limit exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-COINS
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int fx(int n)
{
    if(n<=4)return n;
    int p=max(n,fx(n/2)+fx(n/3)+fx(n/4));
    return p;
}
int main()
{
    int n;
    while(cin>>n)
    {
        cout<<fx(n)<<endl;
    }
    return 0;
}