/****************************************************************************************
*  @author: kzvd4729                                         created: 2017-07-17 15:59:44                      
*  solution_verdict: Wrong Answer                            language: C++                                     
*  run_time (ms):                                            memory_used (MB):                                 
*  problem: https://vjudge.net/problem/LightOJ-1005
****************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
long long int n,k,t,dp[40][1000],i,j,tc=0;
int main()
{
    for(i=1; i<=30; i++)
    {
        for(j=1; j<=900; j++)
        {
            if(j==1)dp[i][j]=i*i;
            else
            {
                dp[i][j]=(dp[i][j-1]*(i-j+1)*(i-j+1))/j;
            }
        }
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if(k==0)
        {
            cout<<"Case "<<++tc<<": "<<1<<endl;
            continue;
        }
        cout<<"Case "<<++tc<<": "<<dp[n][k]<<endl;

    }
    return 0;
}