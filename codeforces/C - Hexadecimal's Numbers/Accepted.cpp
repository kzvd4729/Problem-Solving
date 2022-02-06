/****************************************************************************************
*  @author: kzvd4729                                         created: Oct/06/2017 12:42                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 30 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/9/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,i;
bool ck(long x)
{
    long num=0,p=1;
    while(x)
    {
        long r=x%2;
        num=num+r*p;
        p*=10;
        x/=2;
    }
    if(num<=n)return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(i=1;  ;i++)
    {
        if(!ck(i))break;
    }
    cout<<i-1<<endl;
    return 0;
}