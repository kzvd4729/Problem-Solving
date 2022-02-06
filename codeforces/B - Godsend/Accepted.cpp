/****************************************************************************************
*  @author: kzvd4729                                         created: Aug/19/2017 09:21                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 343 ms                                          memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/841/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long x,c,n;
int main()
{
    ios_base::sync_with_stdio(0);
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