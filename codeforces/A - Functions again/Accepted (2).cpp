/****************************************************************************************
*  @author: kzvd4729                                         created: Sep/22/2017 20:53                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 3100 KB                              
*  problem: https://codeforces.com/contest/788/problem/A
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[200005],tmp[200005],n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<n;i++)
    {
        if(i%2==1)tmp[i]=abs(arr[i]-arr[i+1]);
        else tmp[i]=abs(arr[i]-arr[i+1])*(-1);
    }
    long sump=0,sumn=0,mx=0,mn=0;
    for(long i=1;i<n;i++)
    {
        sump+=tmp[i];
        sumn+=tmp[i];
        mx=max(mx,sump);
        if(i!=1)mn=min(mn,sumn);
        if(sumn>0)sumn=0;
        if(sump<0)sump=0;
    }
    cout<<max(mx,abs(mn))<<endl;
    return 0;
}