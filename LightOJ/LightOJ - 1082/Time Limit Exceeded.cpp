/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-11-20 00:35:53                      
*  solution_verdict: Time Limit Exceeded                     language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1082
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long arr[100005],sp[100005][22],tc,t,n,q;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(long i=1;i<=n;i++)
        {
            cin>>arr[i];
            sp[i][0]=arr[i];
        }
        for(long j=1;j<=20;j++)
        {
            for(long i=1;i<=n;i++)
            {
                if(i+(1<<(j-1))<=n)sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
            }
        }
        long l,r,ans;
        cout<<"Case "<<++tc<<":"<<endl;
        while(q--)
        {
            cin>>l>>r;
            ans=9999999999;
            for(long j=20;j>=0;j--)
            {
                if((l+(1<<j))-1>r)continue;
                ans=min(ans,sp[l][j]);
                l=l+(1<<j);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}