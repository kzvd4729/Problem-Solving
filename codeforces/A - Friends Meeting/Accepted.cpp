/****************************************************************************************
*  @author: kzvd4729                                         created: Mar/04/2018 21:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/931/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long a,b,sum,id;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
     cin>>a>>b;
    if(a>b)swap(a,b);
     sum=0,id=1;
    while(true)
    {
        if(a==b)break;
        a++;
        sum+=id;
        if(a==b)break;
        sum+=id;
        b--;
        id++;
    }
    cout<<sum<<endl;
    return 0;
}