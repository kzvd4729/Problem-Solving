/****************************************************************************************
*  @author: kzvd4729                                         created: Jan/10/2018 10:58                        
*  solution_verdict: Accepted                                language: GNU C++14                               
*  run_time: 436 ms                                          memory_used: 4200 KB                              
*  problem: https://codeforces.com/contest/798/problem/D
****************************************************************************************/
#include<bits/stdc++.h>
#define long long long
using namespace std;
long n,a[100005],b[100005],s[100005],x1,x2;
bool ok(void)
{
long s1=0,s2=0;
for(long i=1;i<=(n/2)+1;i++)
{
s1+=a[s[i]];
s2+=b[s[i]];
}
if(s1*2>x1&&s2*2>x2)return true;
else return false;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
 cin>>n;
for(long i=1;i<=n;i++)cin>>a[i],x1+=a[i];
for(long i=1;i<=n;i++)cin>>b[i],x2+=b[i];
for(long i=1;i<=n;i++)s[i]=i;
while(!ok())random_shuffle(s+1,s+n+1);
cout<<n/2+1<<endl;
for(long i=1;i<=(n/2)+1;i++)cout<<s[i]<<" ";
cout<<endl;
return 0;
}