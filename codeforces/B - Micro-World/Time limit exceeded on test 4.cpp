/****************************************************************************************
*  @author: kzvd4729                                         created: Jun/12/2018 12:52                        
*  solution_verdict: Time limit exceeded on test 4           language: GNU C++17                               
*  run_time: 2000 ms                                         memory_used: 1600 KB                              
*  problem: https://codeforces.com/contest/990/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=2e5;
int n,k,arr[N+2],par[N+2];
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
 cin>>n>>k;
for(int i=1;i<=n;i++)
 cin>>arr[i];
sort(arr+1,arr+n+1);
for(int i=1;i<=n;i++)par[i]=i;
for(int i=1;i<=n;i++)
{
for(int j=i-1;j>=1;j--)
{
if(arr[i]-arr[j]>k)break;
if(arr[i]!=arr[j])par[j]=par[j-1];
}
}
int ans=0;
for(int i=1;i<=n;i++)if(par[i]==i)ans++;
cout<<ans<<endl;
return 0;
}