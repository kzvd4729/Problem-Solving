/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/17/2017 00:32                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 312 ms                                          memory_used: 9700 KB                              
*  problem: https://codeforces.com/contest/898/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,m,k,fre[1000006],x,l,cnt;
int main()
{
    cin>>n>>m>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>x;
        fre[x]++;
    }
//    for(long i=1;i<=10;i++)
//    {
//        cout<<fre[i]<<" ";
//    }
//    cout<<endl;
    for(long i=1;i<=m;i++)
    {
        cnt+=fre[i];
        if(cnt>=k)
        {
            fre[i]=fre[i]-cnt+k-1;
            cnt=k-1;
        }
    }
//    for(long i=1;i<=10;i++)
//    {
//        cout<<fre[i]<<" ";
//    }
//    cout<<endl;
    for(long i=m+1;i<=1000000;i++)
    {
        cnt-=fre[i-m];
        cnt+=fre[i];
        if(cnt>=k)
        {
            fre[i]=fre[i]-cnt+k-1;
            cnt=k-1;
        }
    }
    long ans=0;
    for(long i=1;i<=1000000;i++)
    {
        ans+=fre[i];
    }
    cout<<n-ans<<endl;
    return 0;
}