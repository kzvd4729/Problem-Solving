/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2018 16:19                        
*  solution_verdict: Wrong answer on test 19                 language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/939/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,c1,c2,x,mx;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(long i=1;i<=k;i++)
    {
        cin>>x;
        long tmp=n/x;
        if((tmp*x)>mx)
        {
            mx=tmp*x;
            c1=i;
            c2=tmp;
        }
    }
    if(n==0)
    {
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    cout<<c1<<" "<<c2<<endl;
    return 0;
}