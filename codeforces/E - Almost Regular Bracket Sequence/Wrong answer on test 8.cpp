/****************************************************************************************
*  @author: * kzvd4729                                       created: Dec/27/2018 21:02                        
*  solution_verdict: Wrong answer on test 8                  language: GNU C++14                               
*  run_time: 31 ms                                           memory_used: 9900 KB                              
*  problem: https://codeforces.com/contest/1095/problem/E
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
const int N=1e6;
int bl[N+2],mn[N+2];
int main()
{
 ios_base::sync_with_stdio(0);cin.tie(0);
 int n;cin>>n;string s;cin>>s;
 for(int i=1;i<=n;i++)
 {
  bl[i]=bl[i-1];
  if(s[i-1]=='(')bl[i]++;
  else bl[i]--;
 }
 mn[n]=bl[n];
 for(int i=n-1;i>=1;i--)
  mn[i]=min(mn[i+1],bl[i]);
 int ans=0;
 for(int i=1;i<=n;i++)
 {
  if(s[i-1]=='(')
   if(mn[i]>=2&&bl[n]==2)ans++;
  else
    if(mn[i]>=-2&&bl[n]==-2)ans++;
  if(bl[i]<0)break;
 }
 cout<<ans<<endl;
 return 0;
}