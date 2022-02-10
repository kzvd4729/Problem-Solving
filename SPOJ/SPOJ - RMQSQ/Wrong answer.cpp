/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-10 22:24:31                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/SPOJ-RMQSQ
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,arr[100005],sp[100004][20],q,l,r;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)cin>>arr[i];
    
    for(i=0;i<n;i++)sp[i][0]=arr[i];
    for(j=1;j<=17;j++)
    {
        for(i=0;i+(1<<j)<=n;i++)
        {
            sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
        }
    }
    long long int ans=999999999999;
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        for(i=17;i>=0;i--)
        {
            if(l+(1<<i)-1<=r)
            {
                ans=min(ans,sp[l][i]);
                l=l+(1<<i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}