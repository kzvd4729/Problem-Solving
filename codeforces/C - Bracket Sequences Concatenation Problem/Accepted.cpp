/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 13:40                        
*  solution_verdict: Accepted                                language: GNU C++17                               
*  run_time: 46 ms                                           memory_used: 3400 KB                              
*  problem: https://codeforces.com/contest/990/problem/C
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=3e5;
int n,bf[N+2],af[N+2];
string s;
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n;
for(int nn=1;nn<=n;nn++)
{
cin>>s;
int f=0,cnt=0;
for(int i=0;s[i];i++)
{
if(s[i]=='(')cnt++;
else cnt--;
if(cnt<0)f=1;
}
if(f)bf[nn]=-1;
else bf[nn]=cnt;
 f=0,cnt=0;
for(int i=s.size()-1;i>=0;i--)
{
if(s[i]==')')cnt++;
else cnt--;
if(cnt<0)f=1;
}
if(f==0)af[cnt]++;
}
            long ans=0;
for(int i=1;i<=n;i++)
{
if(bf[i]==-1)continue;
ans+=(af[bf[i]])*1LL;
}
cout<<ans<<endl;
return 0;
}