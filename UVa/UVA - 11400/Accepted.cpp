/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-12-01 08:46:39                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 80                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-11400
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long dp[1003],n;
struct light
{
    long v,k,c,l;
} arr[1004];
bool cmp(light A,light B)
{
    return A.v<B.v;
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
        for(long i=1; i<=n; i++)
        {
            cin>>arr[i].v>>arr[i].k>>arr[i].c>>arr[i].l;
        }
        sort(arr+1,arr+n+1,cmp);
        for(long i=1; i<=n; i++)
        {
            dp[i]=999999999999999;
        }
        dp[0]=0;
        for(long i=1; i<=n; i++)
        {
            long lamp=0;
            for(long j=i; j>=1; j--)
            {
                lamp+=arr[j].l;
                dp[i]=min(dp[i],dp[j-1]+lamp*arr[i].c+arr[i].k);
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}