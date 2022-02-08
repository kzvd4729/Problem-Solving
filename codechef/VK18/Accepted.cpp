/****************************************************************************************
*  @author: kzvd4729                                         created: 04-12-2017 18:03:47                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.22 sec                                        memory_used: 23.3M                                
*  problem: https://www.codechef.com/DEC17/problems/VK18
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long s1,s2,r,dp[1000006],b,t,n;
long cal(long z)
{
    s1=0,s2=0;
    while(z)
    {
        r=z%10;
        z/=10;
        if(r%2==0)s1+=r;
        else s2+=r;
    }
    return abs(s1-s2);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dp[1]=cal(2);
    dp[2]=cal(4)+cal(3)+cal(3);
    for(long i=3;i<=1000000;i++)
    {
        b=i*2;
        dp[i]=dp[i-1]+cal(b)+cal(b-1)*2-cal(i)*2+cal(b-2);
    }
    for(long i=2;i<=1000000;i++)
    {
        dp[i]+=dp[i-1];
    }
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<dp[n]<<endl;
    }
    return 0;
}