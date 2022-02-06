/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 13:27                        
*  solution_verdict: Wrong answer on test 3                  language: GNU C++17                               
*  run_time: 0 ms                                            memory_used: 2400 KB                              
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
if(cnt<=0)af[abs(cnt)]++;
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