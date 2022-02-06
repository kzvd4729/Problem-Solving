/****************************************************************************************
*  @author: kzvd4729                                         created: Apr/05/2017 23:00                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/795/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    while(cin>>n)
    {
        if(n>=3&&n%2==1)
        {
            cout<<7;
            n=n-3;
        }
        while(n)
        {
            n=n-2;
            cout<<1;
         }
        cout<<endl;
    }
    return 0;
}