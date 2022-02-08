/****************************************************************************************
*  @author: kzvd4729                                         created: 24-02-2018 19:38:34                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.00 sec                                        memory_used: 15.7M                                
*  problem: https://www.codechef.com/LTIME57/problems/HILLS
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,arr[102],ans,f,u,d;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>u>>d;
        for(long i=1;i<=n;i++)cin>>arr[i];
        ans=1;
        f=0;
        for(long i=2;i<=n;i++)
        {
            if(arr[i-1]==arr[i])ans=i;
            else if(arr[i]>arr[i-1]&&(arr[i]-arr[i-1])<=u)ans=i;
            else if(arr[i-1]>arr[i]&&(arr[i-1]-arr[i])<=d)ans=i;
            else if(arr[i-1]>arr[i]&&((arr[i-1]-arr[i])>d)&&f==0)
            {
                ans=i;
                f=1;
            }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}