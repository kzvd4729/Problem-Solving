/****************************************************************************************
*  @author: kzvd4729                                         created: 05-01-2018 17:58:31                      
*  solution_verdict: Accepted                                language: C++14                                   
*  run_time: 0.24 sec                                        memory_used: 206.1M                               
*  problem: https://www.codechef.com/JAN18/problems/STRMRG
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long t,n,m,l1,l2,dp[5005][5005];
string s;
vector<char>v1,v2;
long lcs(void)
{
for(long i=1;i<=l1;i++)
{
for(long j=1;j<=l2;j++)
{
if(v1[i-1]==v2[j-1])dp[i][j]=dp[i-1][j-1]+1;
else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
}
}
return dp[l1][l2];
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
        cin>>t;
while(t--)
{
v1.clear();
v2.clear();
memset(dp,0,sizeof(dp));
cin>>n>>m;
cin>>s;
v1.push_back(s[0]);
for(long i=1;i<s.size();i++)
{
if(s[i]!=s[i-1])v1.push_back(s[i]);
}
cin>>s;
v2.push_back(s[0]);
for(long i=1;i<s.size();i++)
{
if(s[i]!=s[i-1])v2.push_back(s[i]);
}
l1=v1.size();
l2=v2.size();
cout<<l1+l2-lcs()<<endl;
}
return 0;
}