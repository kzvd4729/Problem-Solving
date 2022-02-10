/****************************************************************************************
*  @author: kzvd4729                                         created: 2018-03-01 21:50:47                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time (ms): 0                                          memory_used (MB): 15.4                            
*  problem: https://vjudge.net/problem/SPOJ-FASHION
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,sum,n,a[1004],b[1004];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--)
    {
        cin>>n;
        for(long i=1;i<=n;i++)cin>>a[i];
        for(long i=1;i<=n;i++)cin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        sum=0;
        for(long i=1;i<=n;i++)sum+=(a[i]*b[i]);
        cout<<sum<<endl;
    }
    return 0;
}