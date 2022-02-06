/****************************************************************************************
*  @author: kzvd4729                                         created: May/04/2017 21:31                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 200 KB                               
*  problem: https://codeforces.com/contest/805/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i;
    cin>>n;
    char arr[n+2];
    for(i=1;i<=n;i=i+4)
    {
        arr[i]='a';
    }
    for(i=2;i<=n;i=i+4)
    {
        arr[i]='a';
    }
    for(i=3;i<=n;i=i+4)
    {
        arr[i]='b';
    }
    for(i=4;i<=n;i=i+4)
    {
        arr[i]='b';
    }
    for(i=1;i<=n;i++)
    {
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}