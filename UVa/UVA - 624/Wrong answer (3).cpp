/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-14 23:07:11                      
*  solution_verdict: Wrong answer                            language: C++                                     
*  run_time:                                                 memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-624
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int arr[30],dp[30][1000];
int tot,n,call;
int dpprint(void);
int fx(int s,int v)
{
    if(s==n)
    {
        if(v<=tot)
        {
            return v;
        }
        else return 0;
    }
    if(dp[s][v]!=-1)return dp[s][v];
    return dp[s][v]=max(fx(s+1,v+arr[s]),fx(s+1,v));
}
void print(void)
{
    int ans[1000],i,col,k,qm;
    k=-1;
    col=0;
    for(i=1;i<n;i++)
    {
        if(dp[i][col+arr[i-1]]==call)
        {
            ans[++k]=arr[i-1];
            col=col+arr[i-1];
        }
    }
    qm=0;
    for(i=0;i<=k;i++)
    {
        cout<<ans[i]<<" ";
        qm=qm+ans[i];
    }
    if(call-qm>0)cout<<call-qm<<" ";
    cout<<"sum:"<<call<<endl;
}
int main()
{
    int i;
    while(cin>>tot>>n)
    {
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        memset(dp,-1,sizeof(dp));
        call=fx(0,0);
        print();
        ///dpprint();

    }
    return 0;
}