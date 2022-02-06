/****************************************************************************************
*  @author: kzvd4729                                         created: Dec/07/2017 19:56                        
*  solution_verdict: Wrong answer on test 5                  language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 2600 KB                              
*  problem: https://codeforces.com/contest/581/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,k,ans,arr[100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
     cin>>n>>k;
    for(long i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]!=0)ans+=arr[i]/10;
        arr[i]=arr[i]%10;
    }
    sort(arr+1,arr+n+1);
     for(long i=n;i>=1;i--)
    {
        if(k>=10-arr[i])
        {
            k=k-10+arr[i];
            ans++;
        }
    }
    ans+=(k/10);
    cout<<ans<<endl;
     return 0;
}
 