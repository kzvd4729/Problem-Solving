/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/13/2018 16:12                        
*  solution_verdict: Wrong answer on test 2                  language: GNU C++17                               
*  run_time: 15 ms                                           memory_used: 1800 KB                              
*  problem: https://codeforces.com/contest/550/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long k,n,e,m1,m2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>k;
    cout<<"YES"<<endl;
        if(k==1)
    {
        cout<<2<<" "<<1<<endl<<1<<" "<<2<<endl;
        return 0;
    }
     n=k*2+2;
    e=(n*k)/2;
    cout<<n<<" "<<e<<endl;
     m1=k+1;
    m2=k+2;
     for(long i=2;i<m1;i++)cout<<1<<" "<<i<<endl;
    for(long i=2;i<=m1;i++)
    {
        for(long j=i+1;j<=m1;j++)
        {
            cout<<i<<" "<<j<<endl;
        }
    }
    cout<<m1<<" "<<m2<<endl;
    for(long i=n-1;i>m2;i--)cout<<i<<" "<<n<<endl;
    for(long i=m2;i<=n-1;i++)
    {
        for(long j=i+1;j<=n-1;j++)
        {
            cout<<i<<" "<<j<<endl;
        }
    }
    return 0;
}