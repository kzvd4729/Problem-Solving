/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-10-02 11:21:24                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 0                                               memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-437
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[202][202],n,tc;
struct point
{
    long x;
    long y;
    long z;
}arr[200];
bool cmp(point A,point B)
{
    if(A.x!=B.x)return A.x>B.x;
    else if(A.y!=B.y)return A.y>B.y;
    else return A.z>B.z;
}
int main()
{
    ///ofstream cout("out.txt");
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(cin>>n)
    {
        if(n==0)break;
        memset(dp,0,sizeof(dp));
        long id=0;
        for(long i=1;i<=n;i++)
        {
            point xx;
            cin>>xx.x>>xx.y>>xx.z;
            arr[++id]=xx;
            arr[++id]={xx.x,xx.z,xx.y};
            arr[++id]={xx.y,xx.x,xx.z};
            arr[++id]={xx.y,xx.z,xx.x};
            arr[++id]={xx.z,xx.x,xx.y};
            arr[++id]={xx.z,xx.y,xx.x};
        }
        sort(arr+1,arr+id+1,cmp);
        for(long i=1;i<=id;i++)dp[i][i]=arr[i].z;
        long ans=dp[1][1];
        for(long i=2;i<=id;i++)
        {
            for(long j=1;j<i;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(arr[i].x<arr[j].x&&arr[i].y<arr[j].y)dp[i][i]=max(dp[i][i],dp[i][j]+arr[i].z);
            }
        }
        for(long i=1;i<=id;i++)ans=max(ans,dp[id][i]);
        cout<<"Case "<<++tc<<": maximum height = "<<ans<<endl;
    }
    return 0;
}