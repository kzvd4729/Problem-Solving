/****************************************************************************************
*  @author: kzvd4729                                         created: Feb/17/2018 17:02                        
*  solution_verdict: Wrong answer on pretest 8               language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/939/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],l,r,ans,mx,id,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i],arr[n+i]=arr[i];
    cin>>l>>r;
     id=1;
    cnt=1;
    for(long i=l;i<r;i++)ans+=arr[i];
    mx=ans;
     for(long i=n+l-1;i>=1;i--)
    {
        ans+=arr[i];
        ans-=arr[i+(r-l)];
        cnt++;
        if(ans>mx)
        {
            mx=ans;
            id=cnt;
        }
    }
    cout<<id<<endl;
    return 0;
}