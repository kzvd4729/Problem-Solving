/****************************************************************************************
*  @author: kzvd4729                                         created: Jul/24/2017 20:43                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/832/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,k,x;
int main()
{
    cin>>n>>k;
    x=n/k;
    if(x%2==0)
    {
        cout<<"NO"<<endl;
    }
    else cout<<"YES"<<endl;
     return 0;
}