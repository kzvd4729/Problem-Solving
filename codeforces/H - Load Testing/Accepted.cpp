/****************************************************************************************
*  @author: JU_AAA: aniks2645, kzvd4729, prdx9_abir          created: Sep/18/2017 20:40                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 46 ms                                           memory_used: 5800 KB                              
*  problem: https://codeforces.com/contest/847/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],incf[100005],incb[100005],n,tmp1[100005],tmp2[100005],ans;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    for(long i=1;i<=n;i++)tmp1[i]=arr[i];
    incf[1]=0;
    for(long i=2;i<=n;i++)
    {
        if(tmp1[i]>tmp1[i-1])incf[i]=incf[i-1];
        else
        {
            incf[i]=incf[i-1]+tmp1[i-1]-tmp1[i]+1;
            tmp1[i]=tmp1[i-1]+1;
        }
    }
    for(long i=1;i<=n;i++)tmp2[i]=arr[i];
    incb[n]=0;
    for(long i=n-1;i>=1;i--)
    {
        if(tmp2[i]>tmp2[i+1])incb[i]=incb[i+1];
        else
        {
            incb[i]=incb[i+1]+tmp2[i+1]-tmp2[i]+1;
            tmp2[i]=tmp2[i+1]+1;
        }
    }
    ans=min(incf[n],incb[1]);
     for(long i=1;i<n;i++)
    {
        long c=0;
        if(tmp1[i]==tmp2[i+1])c=1;
        ans=min(ans,incf[i]+incb[i+1]+c);
    }
    cout<<ans<<endl;
     return 0;
}