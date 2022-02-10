/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-08 18:52:48                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-COINS
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int fx(int n)
{
    if(n<=4)return mp[n]=n;
    if(mp[n]!=0)return mp[n];
    int p=max(n,fx(n/2)+fx(n/3)+fx(n/4));
    return mp[n]=p;
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