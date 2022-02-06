/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 22:27                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 4700 KB                              
*  problem: https://codeforces.com/contest/847/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,sum[300005],in,vis[300005];
long qm(long x)
{
    return (x*(x+1))/2;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    long nn=n;
    long kk=k;
    for(long i=1; i<=n; i++)
    {
        sum[i]=qm(i-1);
    }
    if(k>sum[n])
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    sum[n+1]=999999999999999999;
    if(k!=0)
    {
        for(long i=2; i<=n; i++)
        {
            if(sum[i]<=k&&sum[i+1]>k)
            {
                k-=sum[i];
                nn=nn-i;
                in=i;
                break;
            }
        }
    }
    while(true)
    {
        if(k==0)break;
        if(nn<0)break;
        for(long i=2; i<=n; i++)
        {
            if(sum[i]<=k&&sum[i+1]>k)
            {
                k-=sum[i];
                nn--;
                vis[i]++;
                break;
            }
        }
    }
    if(nn<0)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    while(nn--)cout<<"()";
    for(long i=1;i<=in;i++)
    {
        cout<<'(';
        while(vis[i]--)cout<<"()";
    }
    for(long i=1;i<=in;i++)
    {
        cout<<')';
    }
    cout<<endl;
         return 0;
}