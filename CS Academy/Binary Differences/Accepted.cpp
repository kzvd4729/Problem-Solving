/****************************************************************************************
*  @author: kzvd4729                                         created:                                          
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 22 ms                                           memory_used: 1148 KB                              
*  problem: 
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,arr[100005],cnt,ans1,ans2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(long i=1;i<=n;i++)cin>>arr[i];
    cnt=0;
    for(long i=1;i<=n;i++)
    {
        if(!arr[i])cnt++;
        else cnt--;
        if(cnt<0)cnt=0;
        ans1=max(ans1,cnt);
    }
    cnt=0;
    for(long i=1;i<=n;i++)
    {
        if(arr[i])cnt++;
        else cnt--;
        if(cnt<0)cnt=0;
        ans2=max(ans2,cnt);
    }
    cout<<ans1+ans2+1<<endl;
    return 0;
}