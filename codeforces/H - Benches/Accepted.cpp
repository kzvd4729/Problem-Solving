/****************************************************************************************
*  @author: kzvd4729#                                        created: Jan/09/2018 20:18                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 15 ms                                           memory_used: 1900 KB                              
*  problem: https://codeforces.com/contest/630/problem/H
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,dp[102][10];
long rec(long nn,long cnt)
{
if(nn>n)
{
if(cnt)return 0;
else return 1;
}
if(cnt==0)return 1;
if(dp[nn][cnt]!=-1)return dp[nn][cnt];
return dp[nn][cnt]=(n+cnt-5)*rec(nn+1,cnt-1)+rec(nn+1,cnt);
}
int main()
{
memset(dp,-1,sizeof(dp));
cin>>n;
cout<<rec(1,5)<<endl;
return 0;
}