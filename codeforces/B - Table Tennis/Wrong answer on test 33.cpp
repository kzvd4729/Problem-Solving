/****************************************************************************************
*  @author: kzvd4729                                         created: Nov/10/2017 11:40                        
*  solution_verdict: Wrong answer on test 33                 language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 0 KB                                 
*  problem: https://codeforces.com/contest/879/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,arr[1003],mx=0,cnt;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(long i=1; i<=n; i++)
    {
        cin>>arr[i];
        arr[i+n]=arr[i];
        mx=max(mx,arr[i]);
    }
    long ans;
    for(long i=1;i<=n;i++)
    {
        if(arr[i]==mx)
        {
            ans=arr[i];
            break;
        }
        cnt=0;
        for(long j=i+1;  ;j++)
        {
            if(arr[j]>arr[i])break;
            else
            {
                cnt++;
                if(cnt==k)break;
            }
        }
        if(cnt==k)
        {
            ans=arr[i];
            break;
        }
     }
    cout<<ans<<endl;
    return 0;
}
 