/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/07/2018 10:23                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 62 ms                                           memory_used: 5700 KB                              
*  problem: https://codeforces.com/contest/608/problem/B
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
string s1,s2;
long l1,l2,zero[200005],one[200005];
int main()
{
cin>>s1>>s2;
l1=s1.size();
l2=s2.size();
for(long i=1;i<=l2;i++)
{
if(s2[i-1]=='0')zero[i]=1;
else one[i]=1;
zero[i]+=zero[i-1];
one[i]+=one[i-1];
}
long ans=0;
for(long i=1;i<=l1;i++)
{
if(s1[i-1]=='0')ans+=one[l2-l1+i]-one[i-1];
else ans+=zero[l2-l1+i]-zero[i-1];
}
cout<<ans<<endl;
return 0;
}