/****************************************************************************************
*  @author: kzvd4729                                         created: 08-11-2017 11:51:30                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.10 sec                                        memory_used: 22.5M                                
*  problem: https://www.codechef.com/NOV17/problems/CLRL
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,r,arr[1000005],f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        f=0;
        long mn=999999999999;
        long mx=-999999999999;
        cin>>n>>r;
        for(long i=1;i<=n;i++)cin>>arr[i];
        for(long i=1;i<=n;i++)
        {
            if(arr[i]<=mx||arr[i]>=mn)f=1;
            if(arr[i]<r)mx=max(mx,arr[i]);
            else mn=min(mn,arr[i]);
        }
        if(f==1)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}