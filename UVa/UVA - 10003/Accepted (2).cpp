/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-08-07 19:21:59                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 160                                             memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10003
****************************************************************************************/
#include<bits/stdc++.h>
#define inf 99999999
using namespace std;
int l,n,arr[100],i,dp[100][100];
void mem(void)
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            dp[i][j]=inf;
        }
    }
}
int fx(int l,int r)
{
    if(l+1==r)return 0;
    if(dp[l][r]!=inf)return dp[l][r];
    for(int i=l+1;i<r;i++)
    {
        dp[l][r]=min(dp[l][r],(fx(l,i)+fx(i,r))+(arr[r]-arr[l]));
    }
    return dp[l][r];
}
int main()
{
    while(cin>>l)
    {
        if(l==0)break;
        cin>>n;
        for(i=1;i<=n;i++)cin>>arr[i];
        arr[0]=0;
        arr[n+1]=l;
        mem();
        cout<<"The minimum cutting is "<<fx(0,n+1)<<"."<<endl;

    }
    return 0;
}