/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/18/2017 21:28                        
*  solution_verdict: Time limit exceeded on test 49          language: GNU C++14                               
*  run_time: 2000 ms                                         memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/841/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long x,c,n;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        if(x%2==1)c++;
    }
    if(c==0)cout<<"Second"<<endl;
    else cout<<"First"<<endl;
    return 0;
}