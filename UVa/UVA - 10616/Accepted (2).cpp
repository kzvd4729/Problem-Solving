/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-04-13 20:29:17                      
*  solution_verdict: Accepted                                language: C++                                     
*  run_time: 70                                              memory_used:                                      
*  problem: https://vjudge.net/problem/UVA-10616
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long int n,q,d,m,st=0,qu;
long int arr[210],dp[210][200][20];
long int fx(long int s,long int v,long int c)
{
    if(c==m)
    {
        if(v%d==0)return 1;
        else return 0;
    }
    if(s==n)return 0;
    if(dp[s][v][c]!=-1)return dp[s][v][c];
    return dp[s][v][c]=fx(s+1,(v+arr[s])%d,c+1)+fx(s+1,v%d,c);
}
int main()
{
    int i;
    while(cin>>n>>q)
    {
        if(n==0&&q==0)break;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"SET "<<++st<<":"<<endl;
        qu=0;
        for(i=0;i<q;i++)
        {
            cin>>d>>m;
            memset(dp,-1,sizeof(dp));
            cout<<"QUERY "<<++qu<<": "<<fx(0,0,0)<<endl;
        }
    }
    return 0;
}